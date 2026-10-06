/*
 * function: func_021EA9F4
 * address:  0x021EA9F4
 * packet:   pkt_ov170_021EA9F4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021DD238 0x021DD238 thumb
 *   func_021E8F50 0x021E8F50 thumb
 */

typedef struct {
    unsigned char pad[0x1C];
    unsigned char lo : 4;
    unsigned char hi : 4;
} Obj;

struct WinMgr;
extern void func_020061E4(unsigned se);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021DD238(char *p);
extern int func_021E8F50(char *p, int v);

#define MGR(p) (*(struct WinMgr **)(*(char **)((char *)(p) + 0x2C) + 0x74))

void func_021EA9F4(Obj *p, int v)
{
    func_020061E4(0x54C);
    if (func_021EF5E8(MGR(p)) == 1)
        p->lo = 2;
    else
        p->lo = 1;
    p->hi = 0;
    func_021DD238((char *)p);
    func_021E8F50((char *)p, v);
}
