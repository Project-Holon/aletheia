"""Minimal PE32 reader for static work on mwccarm.exe: sections, VA and file
offset conversion, strings, immediate xrefs, call sites, x86 disassembly.

Used by ``mwccdbg.py pe ...``; nothing here runs the compiler.
"""
import re
import struct


class PE:
    def __init__(self, path):
        with open(path, "rb") as fh:
            self.data = fh.read()
        d = self.data
        pe = struct.unpack_from("<I", d, 0x3C)[0]
        nsec = struct.unpack_from("<H", d, pe + 6)[0]
        optsz = struct.unpack_from("<H", d, pe + 20)[0]
        opt = pe + 24
        self.base = struct.unpack_from("<I", d, opt + 28)[0]
        self.entry = self.base + struct.unpack_from("<I", d, opt + 16)[0]
        self.secs = []
        so = opt + optsz
        for i in range(nsec):
            name = d[so:so + 8].rstrip(b"\0").decode()
            vsz, va, rsz, raw = struct.unpack_from("<IIII", d, so + 8)
            self.secs.append((name, self.base + va, vsz, raw, rsz))
            so += 40
        # imports
        idir_rva = struct.unpack_from("<I", d, opt + 104)[0]
        self.imports = {}
        if idir_rva:
            off = self.va2off(self.base + idir_rva)
            while True:
                ilt, _, _, name_rva, iat = struct.unpack_from("<IIIII", d, off)
                if not name_rva:
                    break
                dll = self.cstr(self.base + name_rva)
                t = ilt or iat
                k = 0
                while True:
                    e = struct.unpack_from("<I", d, self.va2off(self.base + t) + 4 * k)[0]
                    if not e:
                        break
                    if e & 0x80000000:
                        fn = "#%d" % (e & 0xffff)
                    else:
                        fn = self.cstr(self.base + e + 2)
                    self.imports[self.base + iat + 4 * k] = dll + "!" + fn
                    k += 1
                off += 20

    def va2off(self, va):
        for name, sva, vsz, raw, rsz in self.secs:
            if sva <= va < sva + max(vsz, rsz):
                return va - sva + raw
        raise ValueError(hex(va))

    def off2va(self, off):
        for name, sva, vsz, raw, rsz in self.secs:
            if raw <= off < raw + rsz:
                return off - raw + sva
        return None

    def read(self, va, n):
        o = self.va2off(va)
        return self.data[o:o + n]

    def cstr(self, va):
        o = self.va2off(va)
        e = self.data.index(b"\0", o)
        return self.data[o:e].decode("latin1")

    def text(self):
        for s in self.secs:
            if s[0] == ".text":
                return s
        return self.secs[0]

    def strings(self, minlen=5):
        for m in re.finditer(rb"[\x20-\x7e]{%d,}" % minlen, self.data):
            va = self.off2va(m.start())
            if va:
                yield va, m.group().decode()

    def find_va(self, needle):
        out = []
        for m in re.finditer(re.escape(needle), self.data):
            va = self.off2va(m.start())
            if va:
                out.append(va)
        return out

    def xrefs_imm(self, value):
        """Code addresses whose bytes contain the 32-bit immediate ``value``."""
        name, sva, vsz, raw, rsz = self.text()
        pat = struct.pack("<I", value)
        out = []
        blob = self.data[raw:raw + rsz]
        i = blob.find(pat)
        while i >= 0:
            out.append(sva + i)
            i = blob.find(pat, i + 1)
        return out

    def calls_to(self, target):
        """E8 rel32 call sites that land on ``target``."""
        name, sva, vsz, raw, rsz = self.text()
        blob = self.data[raw:raw + rsz]
        out = []
        for m in re.finditer(rb"\xe8", blob):
            i = m.start()
            if i + 5 > len(blob):
                break
            rel = struct.unpack_from("<i", blob, i + 1)[0]
            if sva + i + 5 + rel == target:
                out.append(sva + i)
        return out

    def disasm(self, va, n=200, count=0):
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        code = self.read(va, n)
        out = []
        for ins in md.disasm(code, va):
            out.append(ins)
            if count and len(out) >= count:
                break
        return out

    def func_start(self, va):
        """Walk back to a likely function start (after CC/C3 padding or push ebp)."""
        o = self.va2off(va)
        d = self.data
        i = o
        while i > o - 0x4000:
            if d[i - 1] in (0xCC, 0x90) and d[i] != 0xCC and d[i] != 0x90:
                return self.off2va(i)
            if d[i - 1] == 0xC3 and (d[i] in (0x55, 0x53, 0x56, 0x57, 0x83, 0x81, 0x8B, 0x51)):
                return self.off2va(i)
            i -= 1
        return None
