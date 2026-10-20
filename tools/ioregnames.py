#!/usr/bin/env python3
"""ioregnames.py: replace raw hardware addresses in src/game with the SDK names.

Generates src/game/sdk_ioreg.h (address macros REG_xxx_ADDR, memory region
macros HW_xxx, and the typed register macros the shared headers use), then
rewrites every literal I/O register address and memory region base in code to
its macro. The replaced text expands to the same token, so the bytes do not
change.

Local definitions of a typed register name (for example
`#define REG_MTX_PUSH (*(vu32 *)0x04000444)`) are deleted when they match the
shared one; they are reported when they differ.

usage
  python tools/ioregnames.py [--root DIR] [--apply] [--lane LANE] [--list FILE]
Dry run by default: prints the files it would change and the lines it skips.
--apply edits only files that --lane (default P3REG) may claim; files held by
another lane are listed as waiting. Re-run when they are free.
"""
import argparse
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
CLAIMS = os.environ.get('CLAIMS_PY', '')

# (offset, SDK name, type, paired with the sub engine at +0x1000)
ENGINE = [
    (0x000, 'DISPCNT', 'u32'), (0x008, 'BG0CNT', 'u16'), (0x00A, 'BG1CNT', 'u16'),
    (0x00C, 'BG2CNT', 'u16'), (0x00E, 'BG3CNT', 'u16'), (0x010, 'BG0OFS', 'u32'),
    (0x014, 'BG1OFS', 'u32'), (0x018, 'BG2OFS', 'u32'), (0x01C, 'BG3OFS', 'u32'),
    (0x020, 'BG2PA', 'u16'), (0x026, 'BG2PD', 'u16'), (0x030, 'BG3PA', 'u16'),
    (0x036, 'BG3PD', 'u16'),
    (0x040, 'WIN0H', 'u16'), (0x042, 'WIN1H', 'u16'), (0x044, 'WIN0V', 'u16'),
    (0x046, 'WIN1V', 'u16'), (0x048, 'WININ', 'u16'), (0x04A, 'WINOUT', 'u16'),
    (0x04C, 'MOSAIC', 'u16'), (0x050, 'BLDCNT', 'u16'), (0x052, 'BLDALPHA', 'u16'),
    (0x06C, 'MASTER_BRIGHT', 'u16'),
]
# single registers, main side only
SINGLE = [
    (0x004, 'DISPSTAT', 'u16'), (0x006, 'VCOUNT', 'u16'),
    (0x060, 'DISP3DCNT', 'u32'), (0x064, 'DISP_CAPCNT', 'u32'),
    (0x0B0, 'DMA0SAD', 'u32'), (0x0B8, 'DMA0CNT', 'u32'), (0x0E0, 'DMA0FILL', 'u32'),
    (0x100, 'TM0CNT_L', 'u16'), (0x102, 'TM0CNT_H', 'u16'),
    (0x104, 'TM1CNT_L', 'u16'), (0x106, 'TM1CNT_H', 'u16'),
    (0x130, 'KEYINPUT', 'u16'),
    (0x180, 'SUBPINTF', 'u16'), (0x184, 'SUBPFIFO_CNT', 'u16'), (0x188, 'SUBPFIFO_SEND', 'u32'),
    (0x1A0, 'MCCNT0', 'u16'), (0x1A2, 'MCD0', 'u16'), (0x1A4, 'MCCNT1', 'u32'),
    (0x1A8, 'MCCMD0', 'u32'), (0x1AC, 'MCCMD1', 'u32'),
    (0x204, 'EXMEMCNT', 'u16'), (0x208, 'IME', 'u16'), (0x210, 'IE', 'u32'), (0x214, 'IF', 'u32'),
    (0x240, 'VRAMCNT_A', 'u8'), (0x241, 'VRAMCNT_B', 'u8'), (0x242, 'VRAMCNT_C', 'u8'),
    (0x243, 'VRAMCNT_D', 'u8'), (0x244, 'VRAMCNT_E', 'u8'), (0x245, 'VRAMCNT_F', 'u8'),
    (0x246, 'VRAMCNT_G', 'u8'), (0x247, 'WVRAMCNT', 'u8'), (0x248, 'VRAMCNT_H', 'u8'),
    (0x249, 'VRAMCNT_I', 'u8'),
    (0x280, 'DIVCNT', 'u16'), (0x290, 'DIV_NUMER', 'u64'), (0x298, 'DIV_DENOM', 'u64'),
    (0x2A0, 'DIV_RESULT', 'u64'), (0x2A8, 'DIVREM_RESULT', 'u64'),
    (0x2B0, 'SQRTCNT', 'u16'), (0x2B4, 'SQRT_RESULT', 'u32'), (0x2B8, 'SQRT_PARAM', 'u64'),
    (0x304, 'POWCNT1', 'u16'),
    (0x330, 'EDGE_COLOR', 'u16'), (0x340, 'ALPHA_TEST_REF', 'u16'),
    (0x350, 'CLEAR_COLOR', 'u32'), (0x354, 'CLEAR_DEPTH', 'u16'),
    (0x356, 'CLRIMAGE_OFFSET', 'u16'), (0x358, 'FOG_COLOR', 'u32'),
    (0x35C, 'FOG_OFFSET', 'u16'), (0x360, 'FOG_TABLE', 'u32'),
    (0x400, 'GXFIFO', 'u32'), (0x440, 'MTX_MODE', 'u32'), (0x444, 'MTX_PUSH', 'u32'),
    (0x448, 'MTX_POP', 'u32'), (0x44C, 'MTX_STORE', 'u32'), (0x450, 'MTX_RESTORE', 'u32'),
    (0x454, 'MTX_IDENTITY', 'u32'), (0x468, 'MTX_MULT_3x3', 'u32'),
    (0x46C, 'MTX_SCALE', 'u32'), (0x470, 'MTX_TRANS', 'u32'),
    (0x480, 'COLOR', 'u32'), (0x484, 'NORMAL', 'u32'), (0x488, 'TEXCOORD', 'u32'),
    (0x48C, 'VTX_16', 'u32'), (0x490, 'VTX_10', 'u32'),
    (0x4A4, 'POLYGON_ATTR', 'u32'), (0x4A8, 'TEXIMAGE_PARAM', 'u32'),
    (0x4AC, 'TEXPLTT_BASE', 'u32'), (0x4C0, 'DIF_AMB', 'u32'), (0x4C4, 'SPE_EMI', 'u32'),
    (0x4C8, 'LIGHT_VECTOR', 'u32'), (0x4CC, 'LIGHT_COLOR', 'u32'), (0x4D0, 'SHININESS', 'u32'),
    (0x500, 'BEGIN_VTXS', 'u32'), (0x504, 'END_VTXS', 'u32'),
    (0x540, 'SWAP_BUFFERS', 'u32'), (0x580, 'VIEWPORT', 'u32'),
    (0x600, 'GXSTAT', 'u32'), (0x604, 'RAM_COUNT', 'u32'), (0x606, 'VERTEX_RAM_COUNT', 'u16'),
    (0x610, 'DISP_1DOT_DEPTH', 'u16'),
    (0x640, 'CLIPMTX_RESULT', 'u32'), (0x680, 'VECMTX_RESULT', 'u32'),
]
# 0x04004000 block (SCFG, NDMA): name guesses from the SDK dsi headers
TWL = [
    (0x4000, 'SCFG_ROM', 'u8'), (0x4004, 'SCFG_CLK', 'u16'), (0x4006, 'SCFG_RST', 'u16'),
    (0x4008, 'SCFG_EXT', 'u32'), (0x4010, 'SCFG_MC', 'u16'),
    (0x4040, 'MI_MC_CNT1', 'u32'), (0x4044, 'MI_MC_CNT2', 'u32'),
    (0x404C, 'MI_MC_CNT3', 'u32'), (0x4054, 'MI_MC_CNT4', 'u32'),
    (0x4058, 'MI_MC_CNT5', 'u32'), (0x405C, 'MI_MC_CNT6', 'u32'),
    (0x4100, 'MI_NDMA_GLOBAL_CNT', 'u32'), (0x4104, 'MI_NDMA_SRC', 'u32'),
    (0x411C, 'MI_NDMA_CNT', 'u32'),
    (0x4200, 'DSP_PDATA', 'u16'), (0x4202, 'DSP_PADR', 'u16'), (0x4204, 'DSP_PCFG', 'u16'),
    (0x4300, 'AES_CNT', 'u32'), (0x4304, 'AES_BLKCNT', 'u32'), (0x4308, 'AES_WRFIFO', 'u32'),
    (0x430C, 'AES_RDFIFO', 'u32'), (0x4310, 'AES_IV', 'u32'), (0x4314, 'AES_MAC', 'u32'),
    (0x4318, 'AES_BLK', 'u32'), (0x431C, 'AES_CTR', 'u32'), (0x4324, 'AES_KEY0', 'u32'),
    (0x432C, 'AES_KEY1', 'u32'), (0x4334, 'AES_KEY2', 'u32'),
]
REGIONS = [
    (0x05000000, 'HW_BG_PLTT'), (0x05000400, 'HW_DB_BG_PLTT'),
    (0x05000200, 'HW_OBJ_PLTT'), (0x05000600, 'HW_DB_OBJ_PLTT'),
    (0x06000000, 'HW_BG_VRAM'), (0x06200000, 'HW_DB_BG_VRAM'),
    (0x06400000, 'HW_OBJ_VRAM'), (0x06600000, 'HW_DB_OBJ_VRAM'),
    (0x06800000, 'HW_LCDC_VRAM'), (0x06860000, 'HW_LCDC_VRAM_D'),
    (0x07000000, 'HW_OAM'), (0x07000400, 'HW_DB_OAM'),
]
# registers that get typed REG_ macros (the shared headers use them)
TYPED = {'GXFIFO', 'MTX_MODE', 'MTX_PUSH', 'MTX_POP', 'MTX_STORE', 'MTX_RESTORE',
         'MTX_IDENTITY', 'MTX_SCALE', 'MTX_TRANS', 'NORMAL', 'TEXCOORD', 'VTX_16',
         'POLYGON_ATTR', 'DIF_AMB', 'SPE_EMI', 'LIGHT_COLOR', 'BEGIN_VTXS', 'END_VTXS',
         'DISPCNT', 'BLDCNT', 'DB_DISPCNT', 'DB_BLDCNT'}
ALIASES = {'GXFIFO': 'REG_GXFIFO', 'REG_DISPCNT_MAIN': 'REG_DISPCNT', 'REG_DISPCNT_SUB': 'REG_DB_DISPCNT',
           'REG_BLDCNT_MAIN': 'REG_BLDCNT', 'REG_BLDCNT_SUB': 'REG_DB_BLDCNT'}
TYPED_HEADERS = ('nns_g3d_sbc_types.h', 'enceff_g3_inline.h', 'irc_screen_types.h')
TYPE_ALIAS = {'u8': 'vu8', 'u16': 'vu16', 'u32': 'vu32', 'u64': 'vu64'}


def build_table():
    regs = []  # (addr, name, type)
    for off, n, t in ENGINE:
        regs.append((0x04000000 + off, n, t))
        regs.append((0x04001000 + off, 'DB_' + n, t))
    for off, n, t in SINGLE:
        regs.append((0x04000000 + off, n, t))
    for off, n, t in TWL:
        regs.append((0x04000000 + off, n, t))
    return regs


def header_text(regs):
    out = []
    out.append('#ifndef GAME_SDK_IOREG_H')
    out.append('#define GAME_SDK_IOREG_H')
    out.append('')
    out.append('#include "types.h"')
    out.append('')
    out.append('/*')
    out.append(' * Hardware I/O register addresses and memory region bases, with the SDK names.')
    out.append(' * REG_xxx_ADDR is the address of a register (the typed registers are in')
    out.append(' * sdk_ioreg_reg.h). A DB_ prefix is the sub engine.')
    out.append(' */')
    out.append('')
    out.append('/* Memory regions. */')
    for a, n in REGIONS:
        out.append('#define %-18s 0x%08X' % (n, a))
    out.append('')
    out.append('/* Register addresses. */')
    for a, n, t in sorted(regs):
        out.append('#define REG_%s_ADDR 0x%08X' % (n, a))
    out.append('')
    out.append('#endif')
    return '\n'.join(out) + '\n'


def reg_header_text(regs):
    out = ['#ifndef GAME_SDK_IOREG_REG_H', '#define GAME_SDK_IOREG_REG_H', '',
           '#include "sdk_ioreg.h"', '',
           '/* Typed (volatile) hardware registers, SDK names. A DB_ prefix is the sub engine. */']
    for a, n, t in sorted(regs):
        if n in TYPED:
            out.append('#define REG_%-14s (*(%s *)REG_%s_ADDR)' % (n, TYPE_ALIAS[t], n))
    out += ['', '#endif']
    return '\n'.join(out) + '\n'


def norm_type(t):
    t = re.sub(r'\s+', ' ', t.strip())
    t = t.replace('volatile unsigned short', 'vu16').replace('volatile unsigned char', 'vu8')
    t = t.replace('volatile unsigned int', 'vu32').replace('volatile unsigned', 'vu32')
    t = t.replace('volatile u8', 'vu8').replace('volatile u16', 'vu16')
    t = t.replace('volatile u32', 'vu32').replace('volatile u64', 'vu64')
    return t


def claim_owner(path):
    if not CLAIMS:
        return 'nobody'
    r = subprocess.run([sys.executable, CLAIMS, 'who', path], capture_output=True, text=True)
    return re.sub(r"[\[\]'\",]", '', (r.stdout.strip() or 'nobody')).split()[0]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--root', default=ROOT)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--lane', default='P3REG')
    ap.add_argument('--list', help='write the files changed or waiting to this file')
    a = ap.parse_args()
    regs = build_table()
    by_addr = {addr: (n, t) for addr, n, t in regs}
    reg_addr_names = {addr: 'REG_%s_ADDR' % n for addr, n, t in regs}
    region_names = {addr: n for addr, n in REGIONS}
    typed = {'REG_' + n: (addr, TYPE_ALIAS[t]) for addr, n, t in regs if n in TYPED}
    game = os.path.join(a.root, 'src', 'game')
    hdr_path = os.path.join(game, 'sdk_ioreg.h')
    want = header_text(regs)
    for hp, wt in ((hdr_path, want), (hdr_path[:-2] + '_reg.h', reg_header_text(regs))):
        cur = open(hp, newline='').read() if os.path.exists(hp) else None
        if cur != wt:
            print('header: %s %s' % ('write' if a.apply else 'would write', hp))
            if a.apply:
                open(hp, 'w', newline='').write(wt)

    lit = re.compile(r'0x0([4567][0-9A-Fa-f]{6})\b')
    defre = re.compile(r'^(\s*#\s*define\s+)([A-Za-z_][A-Za-z0-9_]*)(\s+)\(\*\(([a-z0-9 ]+?)\s*\*\)\s*(0x0[0-9A-Fa-f]{7}|REG_[A-Z0-9a-z_]+_ADDR)\)\s*$')
    known = {v: k for k, v in reg_addr_names.items()}
    known.update({v: k for k, v in region_names.items()})
    changed, waiting, notes = [], [], []
    header_blocked = False
    for dp, dn, fn in os.walk(game):
        for f in fn:
            if f in TYPED_HEADERS:
                rel = os.path.relpath(os.path.join(dp, f), a.root).replace(os.sep, '/')
                if claim_owner(rel) not in ('nobody', a.lane):
                    header_blocked = True
                    notes.append('alias renames off: %s is held' % rel)
    for dp, dn, fn in os.walk(game):
        for f in sorted(fn):
            if not f.endswith(('.c', '.h')) or f in ('sdk_ioreg.h', 'sdk_ioreg_reg.h'):
                continue
            p = os.path.join(dp, f)
            raw = open(p, newline='', encoding='utf-8', errors='surrogateescape').read()
            if '0x04' not in raw and '0x05' not in raw and '0x06' not in raw and '0x07' not in raw \
                    and 'sdk_ioreg' not in raw                     and 'GXFIFO' not in raw and 'REG_DISPCNT_' not in raw and 'REG_BLDCNT_' not in raw:
                continue
            lines = raw.split('\n')
            alias_ok = {}
            for ln in lines:
                mm = re.match(r'^\s*#\s*define\s+(%s)\b' % '|'.join(ALIASES), ln)
                if mm:
                    d = defre.match(ln.rstrip('\r'))
                    good = False
                    if d:
                        t = ALIASES[mm.group(1)]
                        ad = int(d.group(5), 16) if d.group(5).startswith('0x') else next(
                            (x for x, n, ty in regs if 'REG_%s_ADDR' % n == d.group(5)), None)
                        good = (t in typed and typed[t][0] == ad and typed[t][1] == norm_type(d.group(4)))
                    alias_ok[mm.group(1)] = alias_ok.get(mm.group(1), True) and good
                    if not good:
                        notes.append('%s: alias %s kept' % (os.path.relpath(p, game), mm.group(1)))
            new, n_rep, in_c, need_typed = [], 0, False, False
            for ln in lines:
                s = ln.strip()
                code = ln
                # comment handling: block comments by line, line comments by cut
                if in_c:
                    new.append(ln)
                    if '*/' in ln:
                        in_c = False
                    continue
                if s.startswith('/*') or s.startswith('*') or s.startswith('//'):
                    new.append(ln)
                    if s.startswith('/*') and '*/' not in s:
                        in_c = True
                    continue
                if re.match(r'^\s*(ldr|\.word|\.long|dcd|DCD)\b', ln):
                    new.append(ln)
                    continue
                m = defre.match(ln.rstrip('\r'))
                if m and m.group(2) in ALIASES and alias_ok.get(m.group(2)):
                    n_rep += 1
                    need_typed = True
                    continue
                dm = re.match(r'^\s*#\s*define\s+(\w+)\s+(0x0[0-9A-Fa-f]{7}|\w+)\s*$', ln.rstrip('\r'))
                if dm:
                    nm_, val_ = dm.group(1), dm.group(2)
                    if nm_ in known and val_.startswith('0x') and int(val_, 16) == known[nm_]:
                        n_rep += 1
                        continue  # same as the shared macro
                    if nm_ in known:
                        notes.append('%s: local %s differs from shared (%s)' % (os.path.relpath(p, game), nm_, ln.strip()))
                    elif nm_ == val_:
                        continue
                if m and m.group(2) in typed:
                    addr = int(m.group(5), 16) if m.group(5).startswith('0x') else None
                    if addr is None:
                        nm = m.group(5)[4:-5]
                        addr = next((ad for ad, n, t in regs if n == nm), None)
                    taddr, ttype = typed[m.group(2)]
                    if addr == taddr and norm_type(m.group(4)) == ttype:
                        n_rep += 1
                        need_typed = True
                        continue  # same as the shared macro: drop the local copy
                    notes.append('%s: local %s differs from shared (%s)' % (os.path.relpath(p, game), m.group(2), ln.strip()))
                cm = ln.find('//')
                cm2 = ln.find('/*')
                cut = min([x for x in (cm, cm2) if x >= 0] or [len(ln)])
                head, tail = ln[:cut], ln[cut:]

                def sub(mm):
                    v = int('0x0' + mm.group(1), 16)
                    name = reg_addr_names.get(v) or region_names.get(v)
                    if name is None:
                        return mm.group(0)
                    pre = head[:mm.start()].rstrip()
                    post = head[mm.end():].lstrip()
                    is_ptr = bool(re.search(r'\*\s*\)\s*\(?$', pre))
                    if not is_ptr and (pre.endswith(('&', '|', '~', '^', '<<', '>>')) or post.startswith(('|', '&', '^', '<<', '>>'))):
                        if v >= 0x05000000 or v in (0x04000000, 0x04001000):
                            notes.append('%s: kept (mask context) %s' % (os.path.relpath(p, game), ln.strip()[:90]))
                            return mm.group(0)
                    if re.search(r'#\s*define\s+HW_[A-Z_]+\s*$', pre):
                        return mm.group(0)
                    if not is_ptr and (pre.endswith('|') or post.startswith('|')):
                        return mm.group(0)
                    return name
                head2 = lit.sub(sub, head)
                for al, tn in ALIASES.items():
                    if alias_ok.get(al, not header_blocked) and al in head2:
                        n_rep += 1
                        need_typed = True
                        head2 = re.sub(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % al, tn, head2)
                if head2 != head:
                    n_rep += 1
                new.append(head2 + tail)
            if n_rep == 0:
                continue
            text = '\n'.join(new)
            if f in TYPED_HEADERS:
                need_typed = True
            hname = 'sdk_ioreg_reg.h' if need_typed else 'sdk_ioreg.h'
            if hname not in text:
                text = add_include(text, p, game, hname)
            rel = os.path.relpath(p, a.root).replace(os.sep, '/')
            owner = claim_owner(rel)
            if owner not in ('nobody', a.lane):
                waiting.append((rel, owner, n_rep))
                continue
            changed.append((rel, n_rep))
            if a.apply:
                if CLAIMS:
                    subprocess.run([sys.executable, CLAIMS, 'claim', a.lane, rel], capture_output=True)
                open(p, 'w', newline='', encoding='utf-8', errors='surrogateescape').write(text)
    print('changed %d files, waiting %d' % (len(changed), len(waiting)))
    for rel, n in changed:
        print('  ok   %s (%d lines)' % (rel, n))
    for rel, o, n in waiting:
        print('  wait %s (%s, %d lines)' % (rel, o, n))
    for n in notes:
        print('  note ' + n)
    shim = os.path.join(game, 'ov102', 'irc_screen_types.h')
    if a.apply and os.path.exists(shim):
        names = [n for n in ALIASES if n != 'GXFIFO']
        users = []
        for dp, dn, fn in os.walk(game):
            for f in fn:
                if f.endswith(('.c', '.h')) and os.path.join(dp, f) != shim and os.path.basename(dp) in ('ov102', 'ov103'):
                    t = open(os.path.join(dp, f), encoding='utf-8', errors='replace').read()
                    if any(re.search(r'(?<![A-Za-z0-9_])%s(?![A-Za-z0-9_])' % n, t) for n in names):
                        users.append(f)
        txt = open(shim, newline='').read()
        if not users and 'Old names of the SDK registers' in txt:
            lines = [l for l in txt.split('\n')
                     if not l.startswith('/* Old names of the SDK registers')
                     and not re.match(r'#define REG_(DISPCNT|BLDCNT)_(MAIN|SUB) ', l)]
            open(shim, 'w', newline='').write('\n'.join(lines))
            print('removed the old register names from ov102/irc_screen_types.h')
        elif users:
            print('old register names still used by: ' + ', '.join(sorted(users)))
    if a.list:
        with open(a.list, 'w') as fh:
            for rel, n in changed:
                fh.write('ok\t%s\n' % rel)
            for rel, o, n in waiting:
                fh.write('wait\t%s\t%s\n' % (rel, o))


def add_include(text, path, game, hname):
    rel = os.path.relpath(os.path.join(game, hname), os.path.dirname(path)).replace(os.sep, '/')
    inc = '#include "%s"' % rel
    ls = text.split('\n')
    depth = 0
    in_c = False
    at = -1
    strip_re = re.compile(r'/\*.*?\*/|//.*$|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'')
    for i, l in enumerate(ls):
        st = l.strip()
        if in_c:
            if '*/' in st:
                in_c = False
            continue
        if st.startswith('/*') and '*/' not in st:
            in_c = True
            continue
        if st.startswith(('//', '*')):
            continue
        if depth == 0 and re.match(r'\s*#\s*include\b', l):
            at = i + 1
            break
        if not st.startswith('#'):
            code = strip_re.sub('', l)
            depth += code.count('{') - code.count('}')
    if at < 0:
        idx = 0
        for i, l in enumerate(ls):
            if re.match(r'\s*#\s*define\s+\w+_H\b', l):
                idx = i + 1
                break
        else:
            end = text.find('*/')
            idx = text[:end + 2].count('\n') + 1 if text.lstrip().startswith('/*') and end >= 0 else 0
        at = idx
    ls.insert(at, inc)
    return '\n'.join(ls)


if __name__ == '__main__':
    main()
