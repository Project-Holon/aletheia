/*
 * function: FLD_BTL_INST_TOOL_InitTrainerHeader
 * address:  0x021688BC
 * packet:   pkt_ov010_021688BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02082BCC  0x02082BCC  arm
 *   FLD_BTL_INST_TOOL_LoadTrainerGroup  0x0216880C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02082BCC(void *, int, int);
extern void *FLD_BTL_INST_TOOL_LoadTrainerGroup(u32 group, u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct U16Vec;
extern void STRBUF_ToChars(struct U16Vec *, u16 *, u32);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    u8 f8[16];
    u16 f18;
    u16 f1a;
} Blk;

u16 *FLD_BTL_INST_TOOL_InitTrainerHeader(Blk *a, int b, int c)
{
    int h = (int)func_02045B38(0, 2, 11, c);
    u16 *r;
    int t;
    func_02082BCC(a, 0, 0x120);
    r = FLD_BTL_INST_TOOL_LoadTrainerGroup(b, c);
    a->f0 = b + 1;
    a->f18 = 0xFFFF;
    a->f1a = b * 3;
    a->f4 = *r;
    t = (int)func_02045EC0((struct MsgBank *)h, b);
    STRBUF_ToChars((struct U16Vec *)t, (u16 *)a->f8, 16);
    STRBUF_Delete((struct U16Vec *)t);
    MSGDATA_Delete((struct Rec *)h);
    return r;
}
