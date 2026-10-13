/*
 * function: func_021F1028
 * address:  0x021F1028
 * packet:   pkt_ov107_021F1028
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm  arm9
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);

void func_021F1028(int *p)
{
    int r = (int)GFL_NET_HANDLE_GetCurrentHandle();
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)r, 0x40, 4);
    p[1] = 4;
}
