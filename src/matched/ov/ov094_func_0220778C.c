/*
 * function: func_0220778C
 * address: 0x0220778C
 * packet: pkt_ov094_0220778C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero bytes at 0220785A align the next function.
 * lever: indexed entries in the owning structure retain per-field bases;
 *   a raw offset or cast Entry array caches the element and is 138/144 bytes.
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef struct {
    void *f40, *f44, *f48, *f4c, *f50, *f54;
    unsigned int f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry;
typedef struct { char pad[0x40]; Entry entries[8]; } Work;
extern void func_0204A8D4(unsigned int);
extern void func_0204AFD8(unsigned int);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_0220778C(Work *p, int i)
{
    if (p->entries[i].f40 == 0)
        return;
    func_0204A8D4(p->entries[i].f58);
    func_0204A8D4(p->entries[i].f60);
    func_0204A8D4(p->entries[i].f68);
    func_0204A8D4(p->entries[i].f70);
    func_0204AFD8(p->entries[i].f5c);
    func_0204AFD8(p->entries[i].f64);
    func_0204AFD8(p->entries[i].f6c);
    func_0204AFD8(p->entries[i].f74);
    func_0204B3B4(p->entries[i].f40);
    func_0204B3B4(p->entries[i].f44);
    func_0204B3B4(p->entries[i].f48);
    func_0204B3B4(p->entries[i].f4c);
    func_0204B3B4(p->entries[i].f54);
    p->entries[i].f40 = 0;
    p->entries[i].f44 = 0;
    p->entries[i].f48 = 0;
    p->entries[i].f4c = 0;
    p->entries[i].f54 = 0;
    if ((i & 1) == 0) {
        func_0204A8D4(p->entries[i].f78);
        func_0204AFD8(p->entries[i].f7c);
    }
    if (p->entries[i].f50 != 0) {
        func_0204B3B4(p->entries[i].f50);
        p->entries[i].f50 = 0;
    }
}
