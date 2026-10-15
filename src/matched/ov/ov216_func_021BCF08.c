/*
 * function: BEACON_DETAIL_GRA_InitWindows
 * address: 0x021BCF08
 * packet: pkt_ov216_021BCF08
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: final push 2026-10-05 G5L8. EXACT 372 B (c99 and c). Closed by: opt_propagation off with named locals b, a,
 *   rec and off (b, the row offset i*16 and a set in that order in loop 1 before the j loop), do-while loops (with
 *   propagation off a for loop gets an entry guard), x and j as separate counters, j = 0 set only before loop 3
 *   (set before loop 2 it was loaded from x's slot), record address as off + (u32)&w[j] for the add order.
 * symbols:
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BEACON_DETAIL_GRA_DrawRecord 0x021BDA54 thumb ov216
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021BDD8A 0x021BDD8A data a2
 */
struct Four { unsigned short a; unsigned char b, c; };
extern const struct Four d_021BDD8A[];
typedef unsigned int   u32;
typedef unsigned char  u8;
typedef unsigned short u16;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void BEACON_DETAIL_GRA_DrawRecord(char *owner, char *record, u32 b, u16 c, u32 d, u16 f);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(unsigned int);

struct Rec { void *d; int h; int u, v; };
struct Rec32 { void *d; int h; char pad[24]; };
struct Win { struct Rec a[4]; struct Rec32 b; struct Rec32 c; };

#define REC1(w, j, i) ((struct Rec *)((char *)(w) + (j) * 0x80 + (i) * 16))
#define HANDLE(p, k) (*(int *)((p) + (k)))
#define ARG(p, k) (*(int *)((p) + (k) + 0xC))
#define CALLS(r) do { void *d = (r)->d; BMP_WIN_TransferChars(d); BMP_WIN_MakeScreen(d); BG_SYS_PushTile(BMP_WIN_GetBgLayer(d)); } while (0)

#pragma opt_lifetimes off
#pragma opt_propagation off
void BEACON_DETAIL_GRA_InitWindows(char *p)
{
    struct Win *w3;
    struct Win *w2;
    struct Win *w;
    int i, j;
    u8 b;
    u16 a;
    struct Rec *rec;
    int off;
    int x;

    i = 0;
    w = (struct Win *)(p + 0x15C);

    do {
        MSGDATA_ReadString((struct MsgBank *)HANDLE(p, 0x130), i, (void *)ARG(p, 0x130));
        b = d_021BDD8A[i % 2].b;
        off = i * 16;
        a = d_021BDD8A[i % 2].a;
        j = 0;
        do {
            rec = (struct Rec *)(off + (u32)&w[j]);
            BMP_Clear((struct CharBuf *)rec->h, b);
            BEACON_DETAIL_GRA_DrawRecord(p, (char *)rec, 0, 0, ARG(p, 0x130), a);
            CALLS(rec);
            j++;
        } while (j < 2);
        i++;
    } while (i < 4);
    MSGDATA_ReadString((struct MsgBank *)HANDLE(p, 0x130), 7, (void *)ARG(p, 0x130));
    w2 = (struct Win *)(p + 0x130 + 0x2C);

    x = 0;
    do {
        BMP_Clear((struct CharBuf *)w2[x].b.h, 3);
        BEACON_DETAIL_GRA_DrawRecord(p, (char *)&w2[x].b, 0, 0, ARG(p, 0x130), 0x3DC3);
        CALLS(&w2[x].b);
        x++;
    } while (x < 2);
    MSGDATA_ReadString((struct MsgBank *)HANDLE(p, 0x130), 9, (void *)ARG(p, 0x130));
    w3 = (struct Win *)(p + 0x130 + 0x2C);
    j = 0;
    do {
        BMP_Clear((struct CharBuf *)w3[j].c.h, 3);
        BEACON_DETAIL_GRA_DrawRecord(p, (char *)&w3[j].c, 0, 0, ARG(p, 0x130), 0x3DC3);
        CALLS(&w3[j].c);
        j++;
    } while (j < 2);
}
#pragma opt_propagation reset
#pragma opt_lifetimes reset
