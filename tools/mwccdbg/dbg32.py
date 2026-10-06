"""Small Win32 debugger for a 32-bit (WOW64) target, driven from 64-bit Python.

Software breakpoints (int3), each with a Python callback ``cb(dbg, ctx)``,
plus one hardware write watchpoint (DR0).  ``ctx`` is a view of the WOW64
register context: read registers as ``ctx.eax``, write them with
``ctx.set("eax", v)``; writes go back to the thread on resume.  Callbacks
read and write target memory with ``dbg.read`` / ``dbg.write`` / ``dbg.u32``.

Addresses passed to ``bp`` and ``jump`` are preferred-base addresses (image
base 0x400000); the relocation delta is applied when the process starts.
No external debugger is needed.  Windows only.
"""
import ctypes
import ctypes.wintypes as wt
import struct
import subprocess
import traceback

k32 = ctypes.WinDLL("kernel32", use_last_error=True)

DEBUG_ONLY_THIS_PROCESS = 0x2
CREATE_UNICODE_ENVIRONMENT = 0x400
INFINITE = 0xFFFFFFFF
DBG_CONTINUE = 0x00010002
DBG_EXCEPTION_NOT_HANDLED = 0x80010001

EXCEPTION_DEBUG_EVENT = 1
CREATE_THREAD_DEBUG_EVENT = 2
CREATE_PROCESS_DEBUG_EVENT = 3
EXIT_PROCESS_DEBUG_EVENT = 5
LOAD_DLL_DEBUG_EVENT = 6

BP_CODES = (0x80000003, 0x4000001F)   # native / WX86 breakpoint
SS_CODES = (0x80000004, 0x4000001E)   # native / WX86 single step

WOW64_CONTEXT_i386 = 0x00010000
WOW64_CONTEXT_FULL = WOW64_CONTEXT_i386 | 0x17   # control, integer, segments, debug regs


class STARTUPINFOW(ctypes.Structure):
    _fields_ = [("cb", wt.DWORD), ("lpReserved", wt.LPWSTR), ("lpDesktop", wt.LPWSTR),
                ("lpTitle", wt.LPWSTR), ("dwX", wt.DWORD), ("dwY", wt.DWORD),
                ("dwXSize", wt.DWORD), ("dwYSize", wt.DWORD), ("dwXCountChars", wt.DWORD),
                ("dwYCountChars", wt.DWORD), ("dwFillAttribute", wt.DWORD),
                ("dwFlags", wt.DWORD), ("wShowWindow", wt.WORD), ("cbReserved2", wt.WORD),
                ("lpReserved2", ctypes.c_void_p), ("hStdInput", wt.HANDLE),
                ("hStdOutput", wt.HANDLE), ("hStdError", wt.HANDLE)]


class PROCESS_INFORMATION(ctypes.Structure):
    _fields_ = [("hProcess", wt.HANDLE), ("hThread", wt.HANDLE),
                ("dwProcessId", wt.DWORD), ("dwThreadId", wt.DWORD)]


class DEBUG_EVENT(ctypes.Structure):
    # header: code, pid, tid; then a union (largest member about 160 bytes on x64)
    _fields_ = [("dwDebugEventCode", wt.DWORD), ("dwProcessId", wt.DWORD),
                ("dwThreadId", wt.DWORD), ("_pad", wt.DWORD),
                ("u", ctypes.c_ubyte * 176)]


class WOW64_CONTEXT(ctypes.Structure):
    _fields_ = [("ContextFlags", wt.DWORD),
                ("Dr", wt.DWORD * 6),            # Dr0-3, Dr6, Dr7
                ("FloatSave", ctypes.c_ubyte * 112),
                ("SegGs", wt.DWORD), ("SegFs", wt.DWORD), ("SegEs", wt.DWORD),
                ("SegDs", wt.DWORD),
                ("Edi", wt.DWORD), ("Esi", wt.DWORD), ("Ebx", wt.DWORD),
                ("Edx", wt.DWORD), ("Ecx", wt.DWORD), ("Eax", wt.DWORD),
                ("Ebp", wt.DWORD), ("Eip", wt.DWORD), ("SegCs", wt.DWORD),
                ("EFlags", wt.DWORD), ("Esp", wt.DWORD), ("SegSs", wt.DWORD),
                ("ExtendedRegisters", ctypes.c_ubyte * 512)]


k32.WaitForDebugEvent.argtypes = [ctypes.POINTER(DEBUG_EVENT), wt.DWORD]
k32.ContinueDebugEvent.argtypes = [wt.DWORD, wt.DWORD, wt.DWORD]
k32.ReadProcessMemory.argtypes = [wt.HANDLE, ctypes.c_void_p, ctypes.c_void_p,
                                  ctypes.c_size_t, ctypes.POINTER(ctypes.c_size_t)]
k32.WriteProcessMemory.argtypes = [wt.HANDLE, ctypes.c_void_p, ctypes.c_void_p,
                                   ctypes.c_size_t, ctypes.POINTER(ctypes.c_size_t)]
k32.FlushInstructionCache.argtypes = [wt.HANDLE, ctypes.c_void_p, ctypes.c_size_t]
k32.Wow64GetThreadContext.argtypes = [wt.HANDLE, ctypes.POINTER(WOW64_CONTEXT)]
k32.Wow64SetThreadContext.argtypes = [wt.HANDLE, ctypes.POINTER(WOW64_CONTEXT)]
k32.CreateProcessW.argtypes = [wt.LPCWSTR, wt.LPWSTR, ctypes.c_void_p, ctypes.c_void_p,
                               wt.BOOL, wt.DWORD, ctypes.c_void_p, wt.LPCWSTR,
                               ctypes.POINTER(STARTUPINFOW),
                               ctypes.POINTER(PROCESS_INFORMATION)]
k32.CloseHandle.argtypes = [wt.HANDLE]
k32.WaitForSingleObject.argtypes = [wt.HANDLE, wt.DWORD]
k32.TerminateProcess.argtypes = [wt.HANDLE, wt.UINT]


class Ctx:
    """Register view; writes go back to the thread on resume."""

    def __init__(self, raw):
        self.raw = raw
        self.dirty = False

    def __getattr__(self, name):
        if name in ("raw", "dirty"):
            raise AttributeError(name)
        return getattr(self.raw, name.capitalize())

    def set(self, name, value):
        setattr(self.raw, name.capitalize(), value & 0xFFFFFFFF)
        self.dirty = True


class Debugger:
    def __init__(self, exe, args, cwd=None, env=None, image_base=0x400000):
        self.exe = exe
        self.args = args
        self.cwd = cwd
        self.env = env
        self.bps = {}          # addr -> list of callbacks
        self.orig = {}         # addr -> original byte
        self.threads = {}
        self.hproc = None
        self.delta = 0
        self.pref_base = image_base
        self.stop = False
        self.exit_code = None
        self.hits = 0
        self.watch_cb = None
        self.watch_hits = 0

    # ---- memory -------------------------------------------------------
    def read(self, addr, n):
        buf = ctypes.create_string_buffer(n)
        got = ctypes.c_size_t()
        if not k32.ReadProcessMemory(self.hproc, ctypes.c_void_p(addr), buf, n,
                                     ctypes.byref(got)):
            raise OSError("read %08x+%d failed (%d)" % (addr, n, ctypes.get_last_error()))
        return buf.raw[:got.value]

    def write(self, addr, data):
        got = ctypes.c_size_t()
        if not k32.WriteProcessMemory(self.hproc, ctypes.c_void_p(addr), data, len(data),
                                      ctypes.byref(got)):
            raise OSError("write %08x failed (%d)" % (addr, ctypes.get_last_error()))
        k32.FlushInstructionCache(self.hproc, ctypes.c_void_p(addr), len(data))

    def u32(self, a):
        return struct.unpack("<I", self.read(a, 4))[0]

    def s32(self, a):
        return struct.unpack("<i", self.read(a, 4))[0]

    def u16(self, a):
        return struct.unpack("<H", self.read(a, 2))[0]

    def s16(self, a):
        return struct.unpack("<h", self.read(a, 2))[0]

    def u8(self, a):
        return self.read(a, 1)[0]

    def cstr(self, a, maxlen=256):
        if not a:
            return None
        try:
            b = self.read(a, maxlen)
        except OSError:
            return None
        return b.split(b"\0", 1)[0].decode("latin1")

    # ---- breakpoints --------------------------------------------------
    def bp(self, addr, cb):
        """Breakpoint at a preferred-base address.  Several callbacks may
        share one address; they run in the order they were added."""
        self.bps.setdefault(addr, []).append(cb)

    def jump(self, ctx, addr):
        """Resume the thread of ``ctx`` at preferred-base address ``addr``."""
        ctx.set("eip", addr + self.delta)

    def _arm(self, addr):
        real = addr + self.delta
        if addr not in self.orig:
            self.orig[addr] = self.read(real, 1)
        self.write(real, b"\xCC")

    def _disarm(self, addr):
        self.write(addr + self.delta, self.orig[addr])

    def watch_write(self, ctx, addr, cb, size=4):
        """Arm a hardware write watchpoint (DR0) on the thread of ``ctx``.
        Call from inside a breakpoint callback; ``cb(dbg, ctx)`` runs after
        each write, with Eip at the instruction after the writer."""
        lenbits = {1: 0, 2: 1, 4: 3}[size]
        ctx.raw.Dr[0] = addr
        ctx.raw.Dr[5] = (ctx.raw.Dr[5] & ~0x000F0003) | 1 | (1 << 16) | (lenbits << 18)
        ctx.dirty = True
        self.watch_cb = cb

    # ---- context ------------------------------------------------------
    def _getctx(self, th):
        c = WOW64_CONTEXT()
        c.ContextFlags = WOW64_CONTEXT_FULL
        if not k32.Wow64GetThreadContext(th, ctypes.byref(c)):
            raise OSError("Wow64GetThreadContext failed (%d)" % ctypes.get_last_error())
        return c

    def _setctx(self, th, c):
        if not k32.Wow64SetThreadContext(th, ctypes.byref(c)):
            raise OSError("Wow64SetThreadContext failed (%d)" % ctypes.get_last_error())

    def _call(self, cb, ctx):
        try:
            cb(self, ctx)
        except Exception:
            traceback.print_exc()
            self.stop = True

    # ---- run ----------------------------------------------------------
    def run(self):
        """Start the target and run it to exit.  Returns its exit code."""
        cmdline = subprocess.list2cmdline([self.exe] + list(self.args))
        si = STARTUPINFOW()
        si.cb = ctypes.sizeof(si)
        pi = PROCESS_INFORMATION()
        envblk = None
        flags = DEBUG_ONLY_THIS_PROCESS
        if self.env is not None:
            s = "".join("%s=%s\0" % kv for kv in self.env.items()) + "\0"
            envblk = ctypes.create_unicode_buffer(s, len(s))
            flags |= CREATE_UNICODE_ENVIRONMENT
        buf = ctypes.create_unicode_buffer(cmdline)
        if not k32.CreateProcessW(self.exe, buf, None, None, False, flags,
                                  envblk, self.cwd, ctypes.byref(si), ctypes.byref(pi)):
            raise OSError("CreateProcess failed (%d)" % ctypes.get_last_error())
        self.hproc = pi.hProcess
        self.threads[pi.dwThreadId] = pi.hThread
        step_rearm = {}   # tid -> bp addr to re-arm after the single step
        ev = DEBUG_EVENT()
        while True:
            if not k32.WaitForDebugEvent(ctypes.byref(ev), INFINITE):
                raise OSError("WaitForDebugEvent failed")
            code = ev.dwDebugEventCode
            tid = ev.dwThreadId
            status = DBG_CONTINUE
            raw = bytes(ev.u)
            if code == CREATE_PROCESS_DEBUG_EVENT:
                # hFile, hProcess, hThread, lpBaseOfImage (all pointer-sized)
                hfile, _hp, _ht, base = struct.unpack_from("<QQQQ", raw, 0)
                if hfile:
                    k32.CloseHandle(hfile)
                self.delta = base - self.pref_base
                for a in self.bps:
                    self._arm(a)
            elif code == CREATE_THREAD_DEBUG_EVENT:
                self.threads[tid] = struct.unpack_from("<Q", raw, 0)[0]
            elif code == LOAD_DLL_DEBUG_EVENT:
                hfile = struct.unpack_from("<Q", raw, 0)[0]
                if hfile:
                    k32.CloseHandle(hfile)
            elif code == EXIT_PROCESS_DEBUG_EVENT:
                self.exit_code = struct.unpack_from("<I", raw, 0)[0]
                k32.ContinueDebugEvent(ev.dwProcessId, tid, DBG_CONTINUE)
                break
            elif code == EXCEPTION_DEBUG_EVENT:
                exc_code = struct.unpack_from("<I", raw, 0)[0]
                th = self.threads.get(tid)
                if exc_code in BP_CODES:
                    c = self._getctx(th)
                    a = (c.Eip - 1 - self.delta) & 0xFFFFFFFF
                    if a in self.bps and a in self.orig:
                        c.Eip -= 1
                        ctx = Ctx(c)
                        self.hits += 1
                        for cb in self.bps[a]:
                            self._call(cb, ctx)
                        self._disarm(a)
                        c.EFlags |= 0x100
                        self._setctx(th, c)
                        step_rearm[tid] = a
                    # else: the loader's own breakpoint; just continue
                elif exc_code in SS_CODES:
                    c = self._getctx(th)
                    handled = False
                    if c.Dr[4] & 1 and self.watch_cb is not None:
                        c.Dr[4] = 0
                        self.watch_hits += 1
                        self._call(self.watch_cb, Ctx(c))
                        self._setctx(th, c)
                        handled = True
                    if tid in step_rearm:
                        a = step_rearm.pop(tid)
                        if not self.stop:
                            self._arm(a)
                        handled = True
                    if not handled:
                        status = DBG_EXCEPTION_NOT_HANDLED
                else:
                    status = DBG_EXCEPTION_NOT_HANDLED
            k32.ContinueDebugEvent(ev.dwProcessId, tid, status)
            if self.stop:
                k32.TerminateProcess(self.hproc, 1)
                self.stop = False
        # let the process finish tearing down (it holds its working directory)
        k32.WaitForSingleObject(pi.hProcess, 10000)
        k32.CloseHandle(pi.hThread)
        k32.CloseHandle(pi.hProcess)
        return self.exit_code
