/*
 * function: ov208_func_021C0450
 * address:  0x021C0450
 * packet:   pkt_ov208_021C0450
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BBB3C  0x021BBB3C  thumb  ov072
 *   func_0204B294  0x0204B294  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B84C  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

extern void func_02082BCC(void *dst, int v, int n);
struct Actor;
struct Node;
struct Obj;
extern unsigned short func_021BBB3C(char *p, int a, int b);
struct Obj;
extern struct Obj *func_0204B294(void *res, unsigned int a, unsigned int b, unsigned int c, const void *pos, u16 f, u16 heap);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B84C(u32 obj, int v);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern void func_0204B688(struct Actor *actor, u32 value);

#define W(o) (*(u32 *)(p + (o)))

void ov208_func_021C0450(u16 *heap, u8 *p, int key)
{
    ObjPos pos;
    u8 i;

    func_02082BCC(&pos, 0, sizeof(pos));
    for (i = 0; i < 0x3d; i++) {
        pos.x = func_021BBB3C((char *)W(0x3c8), i, 0x19);
        pos.y = func_021BBB3C((char *)W(0x3c8), i, 0x1a);
        *(u32 *)(p + i * 4 + 0xdc) = (u32)func_0204B294((void *)W(0), W(0xb0), W(0xb4), W(0xb8), &pos, 0, *heap);
        func_0204B878((struct Obj *)(*(u32 *)(p + i * 4 + 0xdc)), func_021BBB3C((char *)W(0x3c8), i, 0x18));
        func_0204B92C((struct Obj *)*(u32 *)(p + i * 4 + 0xdc), 1);
        func_0204B84C(*(u32 *)(p + i * 4 + 0xdc), 2);
        CLACT_SetActorDrawPriority((struct Node *)(*(u32 *)(p + i * 4 + 0xdc)), 4);
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0xdc), 0);
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xdc)), 1);
    }
}
