/*
 * function: ZUKAN_SEARCH_SCREEN_LoadGraphics
 * address: 0x021BC474
 * packet: pkt_ov211_021BC474
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   open 0x020490F4 arm
 *   kind 0x02008550 thumb
 *   palette 0x02049B68 arm
 *   screen 0x02049658 arm
 *   tiles 0x020498F4 arm
 *   close 0x02049238 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Object { struct Owner *owner; };
struct Owner { u32 pad; void *context; };
extern void *open(u32,u16);
extern int kind(void *);
extern void palette(void *,u32,u32,u32,u32,u16);
extern void screen(void *,u32,u32,u32,u32,u32,u16);
extern void tiles(void *,u32,u32,u32,u32,u32,u16);
extern void close(void *);
void ZUKAN_SEARCH_SCREEN_LoadGraphics(struct Object *p)
{
    void *arc;
    arc=open(159,0x807E);
    if(kind(p->owner->context)==0) {
        palette(arc,102,2,0x4000,0,126);
        palette(arc,102,2,0x6000,0,126);
        palette(arc,102,6,0x4000,0,126);
        palette(arc,102,6,0x6000,0,126);
    } else {
        palette(arc,103,2,0x4000,0,126);
        palette(arc,103,2,0x6000,0,126);
        palette(arc,103,6,0x4000,0,126);
        palette(arc,103,6,0x6000,0,126);
    }
    screen(arc,105,2,0,0,0,126);
    screen(arc,105,5,0,0,0,126);
    tiles(arc,108,3,0,0,0,126);
    tiles(arc,111,1,0,0,0,126);
    tiles(arc,110,2,0,0,0,126);
    tiles(arc,112,7,0,0,0,126);
    tiles(arc,109,5,0,0,0,126);
    close(arc);
}
