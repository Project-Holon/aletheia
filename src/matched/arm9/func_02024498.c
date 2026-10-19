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
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PRINTSYS_CountControlTag  0x0201D478  thumb
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
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 PRINTSYS_CountControlTag(void *s);
extern void STRBUF_Delete(struct U16Vec *vec);

extern u16 g_0209F724[];

u32 PMSI_PARAM_GetWordCount(u32 a0, u32 a1, u32 a2)
{
    u32 x = (u32)func_02045B38(0, 2, g_0209F724[a0], a2);
    u32 y = (u32)func_02045EC0((struct MsgBank *)x, a1);
    u32 z;

    MSGDATA_Delete((struct Rec *)x);
    z = PRINTSYS_CountControlTag((void *)y);
    STRBUF_Delete((struct U16Vec *)y);

    return z;
}
