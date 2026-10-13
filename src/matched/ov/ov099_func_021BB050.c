/*
 * function: func_021BB050
 * address:  0x021BB050
 * packet:   pkt_ov099_021BB050
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;

typedef struct {
    char pad00[0xe0];
    u32 fe0;
    char pade4[4];
    u32 fe8;
    char padec[0xc];
    u32 ff8;
    char padfc[0x9c];
    void *f198;
} W;

struct Cfg;
struct Descriptor;
extern int func_021BA8BC(void *p);
struct MsgBank;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void  PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

void func_021BB050(W *w)
{
    func_021BA8BC(w->f198);
    w->f198 = (void *)BMP_WIN_Create(3, 5, 1, 0x16, 2, 0xf, 1);
    BMP_WIN_MakeScreen(w->f198);
    MSGDATA_ReadString((struct MsgBank *)w->fe0, 0x12, (void *)w->ff8);
    PRINTSYS_Print(func_02045770(w->f198), 0, 0, (void *)w->ff8, (void *)w->fe8);
    BMP_WIN_TransferChars(w->f198);
}
