/*
 * function: GTSNEGO_MSG_CreateRow
 * address: 0x021D7C48
 * packet: pkt_ov120_021D7C48
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: EXACT* over the 140-byte listing extent; the trailing 2 bytes at
 * 0x021D7CD2 are alignment padding (00 00) before the next function.
 * lever: the slot store is its own statement, `((void **)(p+0x38))[i] = call;`,
 * with q read back from the slot; this keeps p+0x38 (r7) and i*4 (r6) live
 * across the call. A chained `q = slot[i] = call` or an offset local computes
 * the address after the call and frees r7 (132-136 bytes).
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Cfg;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
int GTSNEGO_MSG_CreateRow(u8 *p, int n, int a, int b, int c, int d)
{
    int i;
    void *q;
    for(i=0;i<12;i++) {
        if(!*(void **)(p+i*4+0x38)) {
            ((void **)(p+0x38))[i]=(void *)BMP_WIN_Create((u8)d,(u8)a,(u8)b,(u8)c,2,11,1);
            q=((void **)(p+0x38))[i];
            BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)q),0);
            MSGDATA_ReadString(*(struct MsgBank **)(p+0xc),n,*(void **)(p+0x18));
            PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)q),2,2,*(void **)(p+0x18),*(void **)(p+0x14));
            BMP_WIN_TransferChars((struct Descriptor *)q);
            BMP_WIN_MakeScreen((struct Cfg *)q);
            return i;
        }
    }
    return 0;
}
