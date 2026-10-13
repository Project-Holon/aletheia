p = 'dg1gen.py'
s = open(p).read()
def rep(a, b):
    global s
    assert s.count(a) == 1, a
    s = s.replace(a, b)
rep('''        if ob["addr"] % 4 or ob["size"] % 4:
            continue
        for k in range(ob["size"] // 4):''', '''        if ob["data"] is None or ob["addr"] % 4 or ob["size"] % 4:
            continue
        for k in range(ob["size"] // 4):''')
rep('''    for sec in (".rodata", ".data"):
        lst_ = [ob for ob in objs if ob["sec"] == sec]''', '''    for sec in (".rodata", ".data", ".bss"):
        lst_ = [ob for ob in objs if ob["sec"] == sec]''')
rep('''        ob["name"] = own_names[0] if own_names else "dg_%08X" % ob["addr"]
''', '''        ob["name"] = own_names[0] if own_names else "dg_%08X" % ob["addr"]
        ob["inner_names"] = [(n, a - ob["addr"]) for a in ob["inner"]
                             for nms in hdr_names.get(a, {}).values() for n in nms]
''')
rep('''                    aliases[n] = ob["name"]
    stats["aliases"] = len(aliases)''', '''                    aliases[n] = ob["name"]
        for n, off in ob["inner_names"]:
            aliases[n] = "%s + %d" % (ob["name"], off)
    stats["aliases"] = len(aliases)''')
rep('''        fwd, defs, ext = [], [], set()''', '''        fwd, defs, ext, bdefs = [], [], set(), []''')
rep('''            m = re.compile(DECL_RE % re.escape(name), re.M).search(text)
            fp = re.compile(FP_RE % re.escape(name), re.M).search(text)''', '''            if ob["sec"] == ".bss":
                fwd.append("extern unsigned char %s[%d];" % (name, ob["size"]))
                bdefs.append("unsigned char %s[%d];" % (name, ob["size"]))
                stats["bss"] = stats.get("bss", 0) + 1
                continue
            m = re.compile(DECL_RE % re.escape(name), re.M).search(text)
            fp = re.compile(FP_RE % re.escape(name), re.M).search(text)''')
rep(r'''        body += "\n\n".join(defs) + "\n"''', r'''        body += "\n\n".join(defs) + "\n"
        if bdefs:
            body += "\n/* .bss: mwccarm emits uninitialised definitions in reverse order */\n"
            body += "\n".join(reversed(bdefs)) + "\n"''')
rep('''    return dict(srcdir=srcdir, stats=stats, blockers=blockers, plan=plan, aliases=aliases, **rng)''',
    '''    return dict(srcdir=srcdir, stats=stats, blockers=blockers, plan=plan, aliases=aliases, **rng)
''')
rep('''                          out=os.path.join(OUTB, "link"), data_aliases=r.get("aliases"))''',
    '''                          out=os.path.join(OUTB, "link"), data_aliases=r.get("aliases"), bss=r.get("bss"))''')
rep('''        return emit_companion(rg, objs, files, texts, srcdir, stats, blockers,
                              dict(t0=t0, s0=s0, s1=s1, end=end))''', '''        return emit_companion(rg, objs, files, texts, srcdir, stats, blockers,
                              dict(t0=t0, s0=s0, s1=s1, end=end, bss=(bs, be) if be > bs else None))''')
open(p, 'w').write(s)

p = 'gamelink_dg.py'
s = open(p).read()
rep('out=None, data_aliases=None):', 'out=None, data_aliases=None, bss=None):')
rep('''            if any(x["name"] == ".bss" for t in tus for x in t["tail_secs"]):
                return dict(ov=ovid, ok=False, why="bss in data mode not handled")''', '''            if any(x["name"] == ".bss" for t in tus for x in t["tail_secs"]):
                if not bss:
                    return dict(ov=ovid, ok=False, why="bss in data mode but the overlay has no .bss")
                mem.append(("dbss", bss[0], bss[1] - bss[0]))
                sect.append(" .dbss : { %s } > dbss" % " ".join(
                    "t%d.o (.bss)" % i for i, t in enumerate(tus) if any(x["name"] == ".bss" for x in t["tail_secs"])))''')
open(p, 'w').write(s)
print("ok")
