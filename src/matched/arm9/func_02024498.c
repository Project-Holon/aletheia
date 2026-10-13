/*
 * function: PMSI_PARAM_GetWordCount
 * address:  0x02024498
 * packet:   pkt_02024464
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0209F724  0x0209F724  data
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D478(void *s);
extern void func_02045808(struct U16Vec *vec);

extern u16 g_0209F724[];

u32 PMSI_PARAM_GetWordCount(u32 a0, u32 a1, u32 a2)
{
    u32 x = (u32)func_02045B38(0, 2, g_0209F724[a0], a2);
    u32 y = (u32)func_02045EC0((struct MsgBank *)x, a1);
    u32 z;

    func_02045C04((struct Rec *)x);
    z = func_0201D478((void *)y);
    func_02045808((struct U16Vec *)y);

    return z;
}
