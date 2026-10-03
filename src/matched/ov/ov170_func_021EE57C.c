/*
 * function: func_021EE57C
 * address:  0x021EE57C
 * packet:   pkt_ov170_021EE57C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE408 0x021EE408 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_0203633C 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 */

typedef unsigned int u32;



struct WinMgr;
extern unsigned char func_020260E0(void *obj);
extern unsigned func_02025DE8(void *obj);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_020260E4(void *obj, unsigned char sel);
extern void func_021EE408(char *p, int v);
extern u32 func_020362DC(void);
extern void func_020355D8(int v);
extern unsigned int func_0203633C(void);
extern void func_021DD238(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))

unsigned func_021EE57C(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 0x23 && r <= 0x27) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x21;
        }
        if (r == 0x21) {
            func_020355D8(1);
            return 0x21;
        }
        if (r == 0x22) {
            func_020260E4(OBJ(p), sel);
            return 0x22;
        }
    } else if (r - 0x21 <= 1) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}
