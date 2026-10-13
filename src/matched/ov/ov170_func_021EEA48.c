/*
 * function: func_021EEA48
 * address:  0x021EEA48
 * packet:   pkt_ov170_021EEA48
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
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 */

typedef unsigned int u32;



struct WinMgr;
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern int func_02025DE8(struct Sound *obj);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE408(char *p, int v);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);
extern unsigned int KEY_GetRepeat(void);
extern void func_021DD238(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))

unsigned func_021EEA48(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r - 0x24 <= 2) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            func_020260E4(OBJ(p), sel);
            return 0x23;
        }
    } else if (r - 0x21 <= 2) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (KEY_GetRepeat() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (KEY_GetRepeat() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}
