"""Shared setup for the mwccdbg commands.

Compile settings come from the source file's header (function, address,
region, isa, lang, flags) with command-line overrides, and the compiler and
base flags come from tools/match.py, so a traced compile is the same compile
``match.py one`` runs.  Work files go to a temporary directory under
``env.scratch_dir("mwccdbg")`` and are removed afterwards (``--keep`` keeps
them).  The repo's compiler binary is run in place: breakpoints are written
into the running process only, never into the file.

Also here: readers for compiler structures that more than one command uses
(object names, the pcode opcode table, pcode operands) and the object
disassembly and verdict printed after a compile.
"""
import argparse
import hashlib
import os
import re
import shutil
import struct
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
ROOT = os.path.dirname(TOOLS)
sys.path.insert(0, TOOLS)

import env as toolenv  # noqa: E402
import match  # noqa: E402
from dbg32 import Debugger  # noqa: E402

# Every address in this package is for this build.
VERSION = "1.1p1"
EXE_MD5 = "af8b7f765f672dc3399a557339a181f9"

# ---- CodeGen (backend driver 0x4746A0..0x474D50) ---------------------------
A_FUNC_NAME = 0x474557        # eax = name node of the function, text at +0xA
A_SCHED_PRE_CALL = 0x474976   # call of the scheduler driver before colouring (ARM only)
A_SCHED_POST_CALL = 0x474B5B  # call of the scheduler driver after colouring

# ---- pcode -----------------------------------------------------------------
G_BLOCKS = 0x65B038           # first pcode block
OPC_TABLE = 0x60DC04          # pcode info table, 0x1C per opcode, name pointer first
BLK_NEXT, BLK_FIRST, BLK_LAST = 0x00, 0x14, 0x18
INS_NEXT, INS_PREV = 0x00, 0x04
INS_FLAGS, INS_ALIAS = 0x0C, 0x1C
INS_OP, INS_COND, INS_ARGC, INS_ARGS = 0x28, 0x2A, 0x2C, 0x2E
ARG_SIZE = 0x0E

ARM_REGS = ["r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "sb", "sl", "fp",
            "ip", "sp", "lr", "pc"]


def regname(cls, c):
    if c is None or c < 0:
        return "-"
    if cls == 0 and c < 16:
        return ARM_REGS[c]
    return "%s%d" % ("r" if cls == 0 else "f", c)


# ---------------------------------------------------------------------------
# compile settings
# ---------------------------------------------------------------------------

def add_compile_args(p):
    """Arguments shared by every command that compiles a source file."""
    p.add_argument("src", help="C source; its header supplies the defaults")
    p.add_argument("--func", help="function to report (default: header `function:`)")
    isa = p.add_mutually_exclusive_group()
    isa.add_argument("--thumb", action="store_true")
    isa.add_argument("--arm", action="store_true")
    p.add_argument("--lang", help="-lang value (default: header `lang:`, else none, as match.py)")
    p.add_argument("-O", "--flags", dest="flags",
                   help="optimisation flags, space separated (default: header `flags:`, else -O4,p)")
    p.add_argument("--extra", default="", help="more compiler flags, space separated")
    p.add_argument("--no-sdk-include", action="store_true")
    p.add_argument("--keep", action="store_true", help="keep the work directory")


class Settings:
    """One compile: source, function, ISA, flags."""

    def __init__(self, a):
        self.src = os.path.abspath(a.src)
        if not os.path.exists(self.src):
            raise SystemExit("no such file: %s" % a.src)
        hdr = match.read_header(self.src)
        self.header = hdr
        base = os.path.basename(self.src)
        func = a.func or (hdr.get("function") or "").split(",")[0].strip() or None
        if not func:
            m = re.search(r"(func_[0-9A-Fa-f]{8})", base)
            func = m.group(1) if m else None
        self.func = func
        addr = hdr.get("address")
        if not addr and func:
            m = re.match(r"func_([0-9A-Fa-f]{8})$", func)
            addr = "0x" + m.group(1) if m else None
        self.addr = int(addr, 16) if addr else None
        region = hdr.get("region")
        if not region:
            m = re.match(r"(ov\d{3})_", base)
            region = m.group(1) if m else None
        self.region = region
        if a.thumb or a.arm:
            self.thumb = bool(a.thumb)
        elif hdr.get("isa") in ("thumb", "arm"):
            self.thumb = hdr["isa"] == "thumb"
        else:
            self.thumb = self._isa_from_listing()
        self.lang = a.lang or hdr.get("lang") or None
        self.flags = (a.flags or hdr.get("flags") or "-O4,p").split()
        self.extra = a.extra.split()
        self.sdk = not a.no_sdk_include
        self.keep = a.keep
        cc = (hdr.get("compiler") or "").replace("dsi/", "")
        if cc and cc != VERSION:
            print("note: header names compiler %s; mwccdbg always runs dsi/%s" % (cc, VERSION),
                  file=sys.stderr)

    def _isa_from_listing(self):
        if self.addr is None:
            return False
        try:
            ns = argparse.Namespace(thumb=False, arm=False)
            return match.resolve_isa(self.addr, self.region, ns)
        except (SystemExit, Exception):
            return False

    def args(self, obj):
        """Compiler arguments (without the program), as match.compile_tu builds them."""
        out = list(match.BASE_FLAGS) + self.flags + self.extra
        if self.thumb:
            out += ["-thumb"]
        if self.lang:
            out += ["-lang", self.lang]
        out += ["-ir", os.path.dirname(self.src)]
        # the same argument string match.compile_tu passes
        if self.sdk and os.path.isdir(os.path.join(ROOT, match.SDK_INCLUDE)):
            out += ["-I+" + match.SDK_INCLUDE]
        out += ["-c", "-o", obj, self.src]
        return out

    def describe(self):
        return "%s %s (%s%s, %s)" % (
            os.path.relpath(self.src, ROOT) if self.src.startswith(ROOT) else self.src,
            self.func or "?", "Thumb" if self.thumb else "ARM",
            ", -lang " + self.lang if self.lang else "", " ".join(self.flags + self.extra))


_checked = {}


def compiler_exe():
    exe = match.compiler_path(VERSION)
    if exe not in _checked:
        with open(exe, "rb") as fh:
            md5 = hashlib.md5(fh.read()).hexdigest()
        if md5 != EXE_MD5:
            print("warning: %s is not the build these addresses were read from "
                  "(md5 %s, expected %s)" % (exe, md5, EXE_MD5), file=sys.stderr)
        _checked[exe] = md5
    return exe


class Work:
    """Temporary work directory, removed on exit unless ``keep``."""

    def __init__(self, keep=False):
        self.keep = keep
        self.dir = tempfile.mkdtemp(prefix="run_", dir=toolenv.scratch_dir("mwccdbg"))
        self.obj = os.path.join(self.dir, "tu.o")

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        if self.keep:
            print("[work directory kept: %s]" % self.dir, file=sys.stderr)
        else:
            shutil.rmtree(self.dir, ignore_errors=True)


def run(settings, work, install):
    """Compile under the debugger.  ``install(dbg)`` sets the breakpoints.
    Returns the Debugger after the compiler exits."""
    if os.name != "nt":
        raise SystemExit("mwccdbg drives the compiler with the Win32 debug API; "
                         "it runs on Windows only")
    env = dict(os.environ)
    env.setdefault("MWLibraries", work.dir)
    env.setdefault("MWLibraryFiles", " ")
    d = Debugger(compiler_exe(), settings.args(work.obj), cwd=work.dir, env=env)
    install(d)
    rc = d.run()
    if rc != 0:
        print("compiler exit code %s" % rc, file=sys.stderr)
    return d


# ---------------------------------------------------------------------------
# compiler structures
# ---------------------------------------------------------------------------

class FuncTracker:
    """Follows CodeGen's current function (backend only; IRO passes run
    before CodeGen names the function)."""

    def __init__(self, want=None):
        self.want = want
        self.name = None
        self.listeners = []

    def install(self, d):
        d.bp(A_FUNC_NAME, self._on)

    def _on(self, d, c):
        self.name = d.cstr(c.eax + 0xA, 128)
        for f in self.listeners:
            f(d, c, self.name)

    def active(self):
        return self.name is not None and (self.want is None or self.name == self.want)


class SchedPass:
    """Labels the scheduler driver's two call sites: "pre" (before colouring,
    ARM only) and "post"."""

    def __init__(self):
        self.label = None

    def install(self, d):
        d.bp(A_SCHED_PRE_CALL, lambda d, c: setattr(self, "label", "pre"))
        d.bp(A_SCHED_POST_CALL, lambda d, c: setattr(self, "label", "post"))


class Names:
    """Cached readers for object names and pcode opcode names."""

    def __init__(self):
        self.objs = {}
        self.ops = {}

    def obj(self, d, obj):
        """Name of a compiler object (variable, temp @N, symbol): *(obj+8)+0xA."""
        if not obj:
            return None
        if obj not in self.objs:
            name = None
            try:
                hn = d.u32(obj + 8)
                if hn:
                    name = d.cstr(hn + 0xA, 64)
            except OSError:
                pass
            if name and not name.isprintable():
                name = None
            self.objs[obj] = name
        return self.objs[obj]

    def opcode(self, d, op):
        if op not in self.ops:
            try:
                s = d.cstr(d.u32(OPC_TABLE + op * 0x1C)) or "?"
                s = s.replace("%ss", "s").replace("%s", "")
            except OSError:
                s = "op%d" % op
            self.ops[op] = s
        return self.ops[op]


def read_args(d, ins, limit=24):
    """Operands of one pcode instruction: [(kind, class, flags, value, obj)].

    An operand is 0xE bytes.  kind 0 register: +1 class, +2 effect flags
    (1 use, 2 def), +4 register number.  Other kinds: +2 s32 value (the
    immediate, or the offset of a memory operand), +6 object pointer
    (kind 4: the symbol or variable addressed).  Kind 2 is an immediate,
    kind 6 a branch label (value = target block)."""
    n = max(0, min(d.s16(ins + INS_ARGC), limit))
    raw = d.read(ins + INS_ARGS, n * ARG_SIZE) if n else b""
    out = []
    for k in range(n):
        o = k * ARG_SIZE
        kind = raw[o]
        if kind == 0:
            out.append((0, raw[o + 1], struct.unpack_from("<H", raw, o + 2)[0],
                        struct.unpack_from("<i", raw, o + 4)[0], 0))
        else:
            out.append((kind, raw[o + 1], 0, struct.unpack_from("<i", raw, o + 2)[0],
                        struct.unpack_from("<I", raw, o + 6)[0]))
    return out


def format_insn(d, ins, names, cls=0, nphys=16):
    """``opname defs <- uses`` with vN for virtual registers."""
    defs, uses = [], []

    def rn(rc, v):
        if rc != cls:
            return "%s%d" % ("f" if rc == 1 else "c%d:" % rc, v)
        return regname(cls, v) if v < nphys else "v%d" % v
    for kind, rc, fl, val, obj in read_args(d, ins):
        if kind == 0:
            if fl & 2:
                defs.append(rn(rc, val))
            if fl & 1 or not fl & 2:
                uses.append(rn(rc, val))
        elif kind == 6:
            uses.append("label")
        elif obj:
            nm = names.obj(d, obj) or "obj%x" % obj
            uses.append(nm + ("+%d" % val if val else ""))
        else:
            uses.append("#0x%X" % (val & 0xFFFFFFFF) if abs(val) >= 0x10000 else "#%d" % val)
    return "%-8s %s <- %s" % (names.opcode(d, d.u16(ins + INS_OP)),
                               ",".join(defs) or "-", ", ".join(uses))


def block_insns(d, blk, limit=100000):
    """Instruction pointers of one pcode block, in program order."""
    out = []
    ins = d.u32(blk + BLK_FIRST)
    while ins and len(out) < limit:
        out.append(ins)
        ins = d.u32(ins + INS_NEXT)
    return out


# ---------------------------------------------------------------------------
# output object
# ---------------------------------------------------------------------------

def disasm_function(settings, obj):
    """Lines of the compiled function's disassembly, or a note."""
    if not os.path.exists(obj):
        return ["(no object written)"]
    if not settings.func:
        return ["(no function name; pass --func)"]
    try:
        fb = match.extract_function(obj, settings.func, prefer_thumb=settings.thumb)
    except SystemExit as exc:
        return ["(%s)" % exc]
    out = ["%s: %d bytes" % (settings.func, len(fb.data))]
    for addr, _size, text in match.disasm(fb.data, 0, fb.thumb):
        out.append("  %04x  %s" % (addr, text))
    return out


def verdict(settings, obj):
    """match.py's verdict for the compiled function against the image, as
    one line, or None when the address or region is unknown."""
    if settings.addr is None or not os.path.exists(obj) or not settings.func:
        return None
    try:
        fb = match.extract_function(obj, settings.func, prefer_thumb=settings.thumb)
        reg = match.find_region(settings.addr, settings.region)
        match.resolve_relocations(fb, settings.addr,
                                  match.declared_symbols(settings.header),
                                  src=match.source_key(settings.src), region=reg.name)
        _rname, tgt = match.target_bytes(settings.addr, len(fb.data), region=reg.name)
        status, diffs = match.compare(fb, tgt)
    except (SystemExit, Exception) as exc:
        return "verdict unavailable (%s)" % exc
    if status == "DIFF":
        return "DIFF, %d concrete byte(s) differ" % len(diffs)
    return status
