/*
 * function: func_021DA578
 * address: 0x021DA578
 * packet: pkt_ov129_021DA578
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef short s16;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_020409B4(u32);
void func_021DA578(void *p,int a,void *b,u32 c)
{
    void *ws=func_0201EC64(50);
    void *bank=func_02045B38(0,2,25,50);
    void *msg=func_02045EC0(bank,a);
    void *out=STRBUF_Create(88,50);
    func_0201EFA4(ws,0,c,2,2,1);
    func_0201F250(ws,out,msg);
    BMP_Clear(BMP_WIN_GetBmp(p),15);
    PRINTSYS_Print(BMP_WIN_GetBmp(p),0,0,out,b);
    STRBUF_Delete(out);
    STRBUF_Delete(msg);
    MSGDATA_Delete(bank);
    func_0201ED04(ws);
    BMP_WIN_TransferChars(p);
    func_020409B4(4);
}
