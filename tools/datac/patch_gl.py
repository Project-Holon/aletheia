p = 'gamelink_dg.py'
s = open(p).read()


def rep(a, b):
    global s
    assert s.count(a) == 1, a
    s = s.replace(a, b)


rep('src_dir=None, data_tail=None, out=None):', 'src_dir=None, data_tail=None, out=None, aliases=None):')
rep('''        t["pieces"] = code_pieces(t, ovid, base, end, [u["addr"] for u in tus])''',
    '''        t["pieces"] = [] if t["stem"].endswith(".zdata") else code_pieces(t, ovid, base, end, [u["addr"] for u in tus if not u["stem"].endswith(".zdata")])''')
rep('''    undef -= defined
''', '''    undef -= defined
    undef -= set(aliases or {})
''')
rep('''            for k, p in enumerate(t["pieces"]):
                tag = "t%d" % i if k == 0 else "t%d_%d" % (i, k)''', '''            if t["stem"].endswith(".zdata"):
                # companion data TU: its anchor function goes outside the overlay
                mem.append(("z%d" % i, 0x0E000000 + 0x100 * i, 0x100))
                sect.append(" .z%d : { t%d.o (.text) } > z%d" % (i, i, i))
            for k, p in enumerate(t["pieces"]):
                tag = "t%d" % i if k == 0 else "t%d_%d" % (i, k)''')
rep('''        lcf += "".join(" %s = 0x%08X;\\n" % (n, a) for n, a in absol)''',
    '''        lcf += "".join(" %s = 0x%08X;\\n" % (n, a) for n, a in absol)
        lcf += "".join(" %s = %s;\\n" % (n, c) for n, c in sorted((aliases or {}).items()))''')
rep('''                t["end"] = t["pieces"][0]["end"]
            continue''', '''                t["end"] = t["pieces"][0]["end"] if t["pieces"] else t["addr"]
            continue''')
open(p, 'w').write(s)
print("patched")
