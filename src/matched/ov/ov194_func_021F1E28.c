/*
 * function: func_021F1E28
 * address:  0x021F1E28
 * packet:   pkt_ov194_021F1E28
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note 2026-10-05 (wD7 lane05): the entry spill order (b before a) follows the type of the
 *   fourth parameter: c as u16 closes it (as int the compiler spills a, b, c).
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_021F4DBC  0x021F4DBC  thumb  ov194
 *   func_021F4F50  0x021F4F50  thumb  ov194
 *   func_021F1998  0x021F1998  thumb  ov194
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *   func_021F1FB4  0x021F1FB4  thumb  ov194
 */


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *p, int v, int n);
struct Actor;
struct Cfg;
struct Descriptor;
struct Obj;
struct U16Vec;
struct Vec2;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern int func_021F4DBC(int a, int b);
extern int func_021F4F50(int a);
extern void *func_021F1998(u8 *p, u32 i);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_ToChars(struct U16Vec *vec, u16 *out, u32 n);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_StartActorAnim(struct Actor *a);
extern int func_021F1FB4(u8 *p);
void func_021F1E28(u8 *p, int a, u16 b, u16 c, int d, u8 *e, int f)
{
    u16 pos[2];
    int i;
    int h;
    int base;
    func_02082BCC(p, 0, 0x94);
    i = 0;
    *(int *)(p + 0x34) = c;
    *(u16 *)(p + 0x22) = b;
    *(int *)(p + 0x38) = d;
    h = BMP_WIN_Create(0, 8, 2, 0x18, 2, 15, 1);
    *(int *)(p + 0x40) = h;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
    *(int *)(p + 0x2c) = *(int *)(p + 0x40);
    *(u8 *)(p + 0x30) = i;
    *(int *)(p + 0x3c) = (int)STRBUF_Create(0xe, f);
    for (i = 0; i < 3; i++) {
        *(int *)(p + i * 4 + 0x84) = func_021F4DBC(i, f);
    }
    *(int *)(p + 0x90) = func_021F4F50(f);
    for (i = 0; i < 16; i++) {
        *(int *)(p + i * 4 + 0x44) = (int)func_021F1998(e, i);
    }
    if (STRBUF_GetLength((struct U16Vec *)a) == 0) {
        *(u16 *)p = STRBUF_GetEosChar();
    } else {
        STRBUF_ToChars((struct U16Vec *)a, (u16 *)p, b + 1);
        *(u16 *)(p + 0x1e) = STRBUF_GetLength((struct U16Vec *)a);
    }
    pos[1] = 0x25;
    base = 0x40 - (*(u16 *)(p + 0x22) * 14) / 2;
    if (base < 0) {
        base = 0;
    }
    base += 0x40;
    for (i = 0; i < 16; i++) {
        pos[0] = base + i * 14;
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
        func_0204B92C((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
        func_0204B404((struct Obj *)(*(int *)(p + i * 4 + 0x44)), (const struct Vec2 *)pos, 0);
        func_0204B3DC((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
    }
    for (i = *(u16 *)(p + 0x22); i < 16; i++) {
        func_0204B3DC((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 0);
    }
    CLACT_StartActorAnim((struct Actor *)(*(int *)(p + *(u16 *)(p + 0x1e) * 4 + 0x44)));
    *(int *)(p + 0x28) = 1;
    func_021F1FB4(p);
}
