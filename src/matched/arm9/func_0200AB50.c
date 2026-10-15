/*
 * function: IRC_RANKING_InsertEntry
 * address:  0x0200AB50
 * packet:   pkt_0200AB50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   memcpy  0x02082D44  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 key  : 7;
    u32 off  : 10;
    u32 pad  : 14;
    u32 flag : 1;
    u32 f14;
    u32 f18;
} Ent;

extern void *memcpy(void *dst, const void *src, u32 n);

u8 IRC_RANKING_InsertEntry(Ent *list, s32 n, Ent *dst)
{
    s32 i;
    s32 best = -1;
    s32 k;

    for (i = 0; i < n; i++) {
        if (list[i].flag != 0) {
            if (list[i].key > dst->key) continue;
        }
        best = i;
        break;
    }
    if (best == -1) return 0xff;

    for (k = n - 1; k > best; k--) {
        if (list[k].off != 0 || list[k - 1].off != 0) memcpy(&list[k - 1], &list[k], 0x1c);
    }
    memcpy(dst, &list[best], 0x1c);
    return best;
}
