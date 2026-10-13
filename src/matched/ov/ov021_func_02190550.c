/*
 * function: FIELD_MSGBG_MsgPrintPrintMsg
 * address:  0x02190550
 * packet:   pkt_ov021_02190550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
struct PrintSys;
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);

void FIELD_MSGBG_MsgPrintPrintMsg(Slot *s, int x, int y, u32 z)
{
    u32 t;

    MSGDATA_ReadString((struct MsgBank *)s->f10, z, (void *)s->f18);
    t = s->f0c;
    PRINTSYS_PrintQue((struct PrintSys *)t, (u32)BMP_WIN_GetBmp((struct Descriptor *)s->f1c), (s16)x, (s16)y, (void *)s->f18, s->f08);
    s->f20 = 1;
}
