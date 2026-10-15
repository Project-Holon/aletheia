/*
 * function: PMS_DRAW_UpdateElem
 * address:  0x0202E0E0
 * packet:   pkt_0202E0E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_GetChannelScrollX  0x02041648  arm
 *   BG_SYS_GetChannelScrollY  0x02041664  arm
 *   CLACT_GetActorPos  0x0204B53C  arm
 *   CLACT_SetActorPos  0x0204B528  arm
 */

typedef unsigned char  u8;
typedef signed short   s16;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Pt {
    s16 x;
    s16 y;
};

struct Flags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
};

struct Obj0202E0E0 {
    void *f00;       /* +0x00 */
    u8    f04;       /* +0x04 */
    u8    pad05[3];
    void *actor[2];  /* +0x08, +0x0c */
    s32   x;         /* +0x10 */
    s32   y;         /* +0x14 */
    struct Flags flags; /* +0x18 */
    u8    pad1c[4];
    u32   unk20[2];  /* +0x20, +0x24 */
};

struct Actor;
struct Descriptor;
struct Obj;
struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u32 BG_SYS_GetChannelScrollX(u8 channel);
extern u32 BG_SYS_GetChannelScrollY(u8 channel);
extern void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out);
extern void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);

int PMS_DRAW_UpdateElem(struct Obj0202E0E0 *a0, void *a1, int a2)
{
    int ret;
    s32 i;

    if (a0->f04 != 0) {
        if (PRINTSYS_QUE_IsExistTarget(a1, BMP_WIN_GetBmp(a0->f00)) == 0) {
            BMP_WIN_TransferChars(a0->f00);
            a0->f04 = 0;
        }
    }

    ret = (a0->f04 != 0) ? 1 : 0;
    if (ret == 0) {
        if (a0->flags.b1) {
            for (i = 0; i < 2; i++) {
                if (a0->unk20[i] != 0 && a0->flags.b2) {
                    CLACT_SetActorDrawEnable(a0->actor[i], 1);
                } else {
                    CLACT_SetActorDrawEnable(a0->actor[i], 0);
                }
            }
        }
    }

    if (a2 != 0) {
        s32 v = (s32)BMP_WIN_GetBgLayer(a0->f00);
        struct Pt diff = { 0, 0 };
        struct Pt pos;
        s32 nx;
        s32 ny;
        nx = BG_SYS_GetChannelScrollX((u8)v);
        ny = BG_SYS_GetChannelScrollY((u8)v);

        if (nx != a0->x) {
            diff.x = a0->x - nx;
            a0->x = nx;
        }

        if (ny != a0->y) {
            diff.y = a0->y - ny;
            a0->y = ny;
        }

        if (diff.x != 0 || diff.y != 0) {
            for (i = 0; i < 2; i++) {
                CLACT_GetActorPos(a0->actor[i], &pos);
                pos.x += diff.x;
                pos.y += diff.y;
                CLACT_SetActorPos(a0->actor[i], &pos);
            }
        }
    }

    return ret;
}
