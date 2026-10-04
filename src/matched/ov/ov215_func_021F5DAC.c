/*
 * function: func_021F5DAC
 * address: 0x021F5DAC
 * packet: pkt_ov215_021F5DAC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * lever: first types search split the full-word per-element pointer assignment and named the table address and resource result; declarations ported to block tops with initializer timing preserved.
 * checks: 1 own callee bodies prove 2/7/5/4/1/1/7/2 arities and visible full-word B294 return; 2 no ov214/215/216 constructor twin, own request builder read; 3 carried const/struct compiles remain exhausted2/2; 4 enum-zero, hoisted-zero, per-element pointer and byte-colour idioms read, manual order2/2 unchanged; 5 fresh full idiom inventory and own neighbours read. First types search stopped at200 with MATCH140; clean independent one EXACT140, all9 sites resolved. No manual scheduling variant added.
 * Return ABI: B294 original0204B314 calls CFDC then0204B318/31C returns without overwriting r0; CFDC0204D040 restores full object pointer. Caller021F5E20 stores this r0 and forwards it to B92C. Own B294 void declaration is superseded here by consumed return evidence.
 * Forwarding: 64FC adds4 to r0 and tails through6504 to662C;662C is ldr r0,[r0]; bx lr. All one full-word input/output.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021F64FC 0x021F64FC thumb ov215
 *   table 0x021F7124 data ov215
 */
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204AC18(void *, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short, unsigned short);
extern int func_0204A6C8(void *, unsigned int, unsigned int, unsigned int, unsigned short);
extern int func_0204AF28(void *, unsigned int, unsigned int, unsigned int);
extern void func_02049238(void *);
extern unsigned int func_021F64FC(unsigned int);
extern unsigned int func_0204B294(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern const unsigned int table[][2];
struct Context {
    unsigned short heap;
    unsigned short pad2;
    unsigned int owner;
    char pad8[36];
    unsigned int resource1, resource2, resource3;
    unsigned int objects[6];
    char tail[60];
};
void func_021F5DAC(int unused, struct Context *p)
{
    unsigned char i;
    void *h = func_020490F4(189, p->heap);
    char *tmp1;
    unsigned int tmp2;
    int tmp;
    p->resource2 = func_0204AC18(h, 3, 0, 0, 0, 1, p->heap);
    tmp = func_0204A6C8(h, 2, 0, 0, p->heap);
    if (unused) {
    }
    p->resource1 = tmp;
    p->resource3 = func_0204AF28(h, 1, 0, p->heap);
    func_02049238(h);
    for (i = 0; i < 6; i++) {
        struct Context *out;
        unsigned int o;
        tmp1 = (char *)p;
        tmp1 = tmp1 + (i * 4);
        out = (struct Context *)tmp1;
        tmp2 = (unsigned int)table[i];
        o = func_0204B294(func_021F64FC(p->owner), p->resource1, p->resource2, p->resource3, tmp2, 0, p->heap);
        out->objects[0] = o;
        func_0204B92C((struct Obj *)o, 0);
    }
}
