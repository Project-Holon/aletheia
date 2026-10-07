/*
 * function: MBi_CommParentSendMsg
 * address:  0x021F276C
 * packet:   pkt_ov107_021F276C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_parent.o).  decl_line 792, local hd
 * (MBCommParentBlockHeader).
 *
 * symbols:
 *   mbc   0x021F6FA0  data
 *   func_021F6890   0x021F6890  arm
 *   func_021F3C80   0x021F3C80  arm
 */
typedef unsigned short u16;
typedef unsigned char u8;

extern void *mbc;
extern void func_021F6890(void *hd, void *mbc);
extern void func_021F3C80(int type, u16 pollbmp, void *mbc);

typedef struct
{
    u8 type;
    u8 pad1[1];
    u16 fid;
    u16 seqno;
} MBCommParentBlockHeader;

void MBi_CommParentSendMsg(u8 type, u16 pollbmp)
{
    MBCommParentBlockHeader hd;

    hd.type = type;
    func_021F6890(&hd, mbc);
    func_021F3C80(6, pollbmp, mbc);
}
