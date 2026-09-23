#!/usr/bin/env python3
"""Pseudo-family clustering for the unanchored tail region 0x02051B84..0x020A9000.

No __FILE__ anchors cover this half of the image, so families.py's anchor-bisect
approach can't attribute functions to a source file. Instead we cluster by
address-adjacency reinforced by shared callees / shared data objects: a proxy
for "these were probably linked from the same translation unit".

Algorithm
---------
Walk open+matched game functions in address order (sdk/runtime excluded: they
are not decompilation targets and carry no unit identity of their own, though
they still count as call targets/data for the sharing test).
Start a new cluster at the first function. For each next function, check
whether it shares >=1 callee or >=1 data-object with ANY function in the
previous ~8 functions (WINDOW). If yes, extend the run. If a run of >=3
consecutive functions in a row each fail this test, close the cluster before
the gap and start fresh after it (the failing run starts a new cluster).
Clusters are then capped at ~40 functions (split greedily preserving order),
and any singleton cluster (0 or 1 members, in practice clusters of size 1)
is merged into whichever neighbour (prev preferred) it shares more evidence
with, or the previous cluster if no signal.
"""
import sys, os, json, bisect, collections
os.chdir("<home>/Documents/aletheia")
sys.path.insert(0, "tools")
import worklist as w

REGION_LO = 0x02051B84
REGION_HI = 0x020A9000
WINDOW = 8
BREAK_RUN = 3
CAP = 40

inv = w.build_inventory()
funcs_all = inv["funcs"]
by_addr = inv["by_addr"]

# ---- data object starts (sorted) for pool-word -> data-object resolution ----
data_starts = []
for ln in open("layout/data_objects.txt"):
    if ln.startswith("#") or not ln.strip():
        continue
    parts = ln.split(None, 3)
    if len(parts) < 3 or parts[0] != "arm9":
        continue
    try:
        addr = int(parts[1], 16)
    except ValueError:
        continue
    data_starts.append(addr)
data_starts.sort()


def data_object_of(addr):
    """Resolve a pool-word value to the data-object start that owns it, or None."""
    i = bisect.bisect_right(data_starts, addr) - 1
    if i < 0:
        return None
    return data_starts[i]


# ---- invert callers/pointers (target->srcs) into src->targets ----
callees = collections.defaultdict(set)   # func addr -> set of callee func addrs (bl/blx targets)
for tgt, srcs in inv["callers"].items():
    for s in srcs:
        callees[s].add(tgt)

data_refs = collections.defaultdict(set)  # func addr -> set of data-object addrs referenced
for tgt, srcs in inv["pointers"].items():
    # tgt here is itself a function address (pointers only recorded when target in by_addr);
    # this captures function-pointer refs, keep them as "callee-ish" signal too
    for s in srcs:
        callees[s].add(tgt)

# also mine raw word_refs beyond function addresses, for real data-object refs.
# re-parse via parse_all so we get pointer refs whose target is NOT a function
# (inv['pointers'] only stored refs where tgt in by_addr). Re-derive from items.
units = w.load_units()
funcs_raw, items, edges, word_refs = w.parse_all(units)
starts_all = [f["addr"] for f in funcs_raw]
region_end_all = units["base"] + units["size"]


def owning_func(addr):
    i = bisect.bisect_right(starts_all, addr) - 1
    if i < 0:
        return None
    fn = funcs_raw[i]
    ext_end = starts_all[i + 1] if i + 1 < len(starts_all) else region_end_all
    if addr >= ext_end:
        return None
    return fn["addr"]


for src, val in word_refs:
    if src is None:
        continue
    fa = owning_func(src)
    if fa is None:
        continue
    tgt = val & ~1
    do = data_object_of(tgt)
    if do is not None:
        data_refs[fa].add(do)

# also fold bl/blx edges directly (covers thumb/arm targets outside by_addr too,
# e.g. sdk/runtime targets still count as shared "callee" signal)
for src, tgt, mn in edges:
    if src is None or tgt is None:
        continue
    if mn.startswith("b"):
        callees[src].add(tgt)

# ---- region function list: matched + open (game code only) ----
region_funcs = [f for f in funcs_all if REGION_LO <= f["addr"] < REGION_HI
                and f["cls"] in ("matched", "open")]
region_funcs.sort(key=lambda f: f["addr"])

print("region game functions (matched+open):", len(region_funcs))
print("  matched:", sum(1 for f in region_funcs if f["cls"] == "matched"))
print("  open:", sum(1 for f in region_funcs if f["cls"] == "open"))


def shares(a_addr, b_addr):
    ca, cb = callees.get(a_addr, ()), callees.get(b_addr, ())
    if ca and cb and (ca & cb):
        return True
    da, db = data_refs.get(a_addr, ()), data_refs.get(b_addr, ())
    if da and db and (da & db):
        return True
    return False


# ---- pass 1: adjacency + sharing-within-window run clustering ----
raw_clusters = []
cur = [region_funcs[0]]
fail_run = 0
for idx in range(1, len(region_funcs)):
    fn = region_funcs[idx]
    window = region_funcs[max(0, idx - WINDOW):idx]
    hit = any(shares(fn["addr"], w2["addr"]) for w2 in window)
    if hit:
        cur.append(fn)
        fail_run = 0
    else:
        fail_run += 1
        if fail_run >= BREAK_RUN:
            # the failing run (last BREAK_RUN-1 appended already went into cur one at a
            # time; back them out into the new cluster start). Simpler: we track
            # fail_run but functions were still appended to cur during the run since
            # hit was False each time -> need to correct: don't append on miss until
            # we know whether run continues. Redo with lookahead-free simple rule:
            pass
        cur.append(fn)

# The above naive loop doesn't actually break clusters (miss just appends anyway).
# Re-implement properly below with a clean state machine.
raw_clusters = []
cur = [region_funcs[0]]
miss_streak = 0
pending_miss = []  # functions accumulated during a miss streak, not yet committed
for idx in range(1, len(region_funcs)):
    fn = region_funcs[idx]
    window = region_funcs[max(0, idx - WINDOW):idx]
    hit = any(shares(fn["addr"], w2["addr"]) for w2 in window)
    if hit:
        # commit any pending miss-streak functions into the current cluster
        # (streak broke before reaching BREAK_RUN)
        cur.extend(pending_miss)
        pending_miss = []
        cur.append(fn)
        miss_streak = 0
    else:
        pending_miss.append(fn)
        miss_streak += 1
        if miss_streak >= BREAK_RUN:
            # close current cluster (without the miss streak), start new cluster
            # with the miss-streak functions
            raw_clusters.append(cur)
            cur = pending_miss
            pending_miss = []
            miss_streak = 0
# flush
cur.extend(pending_miss)
if cur:
    raw_clusters.append(cur)

print("pass-1 clusters (pre-cap, pre-merge):", len(raw_clusters))

# ---- pass 2: cap at ~40 functions, split greedily ----
capped = []
for c in raw_clusters:
    if len(c) <= CAP:
        capped.append(c)
    else:
        for i in range(0, len(c), CAP):
            capped.append(c[i:i + CAP])

# ---- pass 3: merge singleton (size-1) clusters into a neighbour ----
def cluster_shares_score(clu_a, clu_b):
    score = 0
    aset_c = set()
    aset_d = set()
    for f in clu_a:
        aset_c |= callees.get(f["addr"], set())
        aset_d |= data_refs.get(f["addr"], set())
    for f in clu_b:
        score += len(aset_c & callees.get(f["addr"], set()))
        score += len(aset_d & data_refs.get(f["addr"], set()))
    return score


merged = list(capped)
changed = True
while changed:
    changed = False
    for i, c in enumerate(merged):
        if len(c) != 1:
            continue
        if len(merged) == 1:
            break
        prev_i = i - 1 if i > 0 else None
        next_i = i + 1 if i + 1 < len(merged) else None
        # prefer neighbour with higher share score; tie -> prev; else prev if exists else next
        cand = []
        if prev_i is not None:
            cand.append((cluster_shares_score(c, merged[prev_i]), prev_i))
        if next_i is not None:
            cand.append((cluster_shares_score(c, merged[next_i]), next_i))
        if not cand:
            continue
        cand.sort(key=lambda x: (-x[0], x[1] != prev_i if prev_i is not None else 0))
        best_score, best_i = cand[0]
        target = merged[best_i]
        if best_i < i:
            merged[best_i] = target + c
        else:
            merged[best_i] = c + target
        del merged[i]
        changed = True
        break  # restart scan since list mutated

print("clusters after cap+singleton-merge:", len(merged))

# re-split any cluster that grew past CAP again due to merges (rare, keep simple: allow slack to 1.25x CAP else split)
final = []
for c in merged:
    if len(c) <= int(CAP * 1.25):
        final.append(c)
    else:
        for i in range(0, len(c), CAP):
            final.append(c[i:i + CAP])

print("final cluster count:", len(final))

# ---- naming: dominant matched-name prefix, else first address ----
import re
RAW_NAME_RE = re.compile(r'^(func|sub|unit)_[0-9A-Fa-f]{8}$')


def cluster_name(c):
    names = [f.get("matched_name") for f in c if f["cls"] == "matched" and f.get("matched_name")]
    # matched_name for game funcs is typically func_XXXXXXXX / sub_XXXXXXXX /
    # unit_XXXXXXXX raw placeholders in this unanchored region -- those carry
    # no naming information (they're just the address again). Only a name
    # that survives this filter is a real source-derived symbol.
    real = [n for n in names if not RAW_NAME_RE.match(n)]
    pool = real
    if pool:
        # find common file-ish prefix: split on '_' and take longest common leading token run
        def toks(n):
            return n.split("_")
        tok_lists = [toks(n) for n in pool]
        # count first-token frequency (dominant module prefix)
        first_tok_counts = collections.Counter(t[0] for t in tok_lists if t)
        dom_tok, cnt = first_tok_counts.most_common(1)[0]
        if cnt >= max(2, len(pool) // 3):
            # try to extend with second token too if also dominant
            two_tok_counts = collections.Counter(
                "_".join(t[:2]) for t in tok_lists if len(t) >= 2 and t[0] == dom_tok
            )
            if two_tok_counts:
                dom2, cnt2 = two_tok_counts.most_common(1)[0]
                if cnt2 >= max(2, cnt // 2):
                    return dom2
            return dom_tok
        # fallback: most common full name minus trailing numeric/hash-ish token
        return pool[0]
    return None


rows = []
for c in final:
    name = cluster_name(c)
    m = [f for f in c if f["cls"] == "matched"]
    o = [f for f in c if f["cls"] == "open"]
    ob = sum(f["code_bytes"] for f in o)
    a0 = c[0]["addr"]
    a1 = c[-1]["addr"]
    key = ("%s@%08X" % (name, a0)) if name else ("pkt_%08X" % a0)
    rows.append({
        "name": key, "fns": len(c), "matched": len(m), "open": len(o), "open_bytes": ob,
        "from": a0, "to": a1,
        "open_list": [(f["addr"], f["code_bytes"]) for f in o],
        "members": [f["addr"] for f in c],
    })

rows.sort(key=lambda r: -r["open_bytes"])

OUT_TXT = os.environ.get("OUT_TXT", "pseudo_families.txt")
OUT_JSON = os.environ.get("OUT_JSON", "pseudo_families.json")

with open(OUT_TXT, "w") as f:
    lines = []
    for i, r in enumerate(rows, 1):
        ol = " ".join("%X/%d" % (a, b) for a, b in r["open_list"][:12])
        line = "%-4d %-34s %5d %5d %5d %7d  %08X %08X  %s" % (
            i, r["name"], r["fns"], r["matched"], r["open"], r["open_bytes"],
            r["from"], r["to"], ol)
        lines.append(line)
    f.write("\n".join(lines) + "\n")

with open(OUT_JSON, "w") as f:
    json.dump(rows, f, indent=1)

print("wrote", OUT_TXT, "and", OUT_JSON)
print()
print("TOP 20:")
for line in open(OUT_TXT).read().splitlines()[:20]:
    print(line)

zero_matched_open = sum(r["open"] for r in rows if r["matched"] == 0)
total_open_covered = sum(r["open"] for r in rows)
print()
print("clusters:", len(rows))
print("total open functions covered:", total_open_covered)
print("open functions in zero-matched-sibling clusters:", zero_matched_open)
print("clusters with zero matched siblings:", sum(1 for r in rows if r["matched"] == 0))
