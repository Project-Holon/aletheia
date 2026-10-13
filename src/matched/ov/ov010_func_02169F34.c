/*
 * function: REPORT_EVENT_UpdatePrintStream
 * address:  0x02169F34
 * packet:   pkt_ov010_02169F34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Rec;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 v);

#define Q (*(u8 **)(p + 0x18))
#define H (*(u32 *)(Q + 0x10))
#define ST (*(u32 *)(Q + 0x20))

int REPORT_EVENT_UpdatePrintStream(u8 *p)
{
    switch (func_0201CE30((void *)H)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (func_0203630C() & 3) != 0)
            func_0201CE5C((struct Rec *)H, 0);
        ST = 0;
        break;
    case 1:
        if (ST == 0) {
            if (TOUCHPANEL_GetTrg() == 1 || (func_020362DC() & 3) != 0) {
                func_020061E4(0x547);
                func_0201CE38((void *)H);
                ST = 1;
            }
        }
        break;
    case 2:
        func_0201CE48((struct Rec3 *)H);
        ST = 0;
        return 0;
    }
    return 1;
}
