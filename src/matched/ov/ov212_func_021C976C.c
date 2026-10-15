/*
 * function: ZUKAN_SEARCH_ENGINE_LoadSpeciesIds
 * address: 0x021C976C
 * packet: pkt_ov212_021C976C
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   alloc 0x02030734 arm
 *   release 0x020307B0 arm
 *   load 0x0204A298 arm
 *   names 0x0201AF80 thumb
 *   site 0x021C99A8 data ov212 a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *alloc(u32,u32,int,const char *,u16);
extern void release(void *);
extern void *load(int,int,int,int,u32 *);
extern u16 *names(int,u16 *);
extern const char site[];
u32 ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(u32 mode,int heap,u16 **out)
{
    u16 *result;
    u16 *map;
    u16 *ids;
    u16 count;
    u32 bytes;
    u16 used;
    u16 i;
    u16 n;
    if (mode == 0) {
        used = 0;
        result = alloc(heap,1298,0,site,825);
        do {
            result[used] = used + 1;
            used = used + 1;
        } while (used < 649);
        *out = result;
        return 649;
    }
    map = names(heap,&count);
    used = 0;
    ids = load(98,4,0,heap,&bytes);
    n = (u16)(bytes / 2);
    result = alloc(heap,count * 2,0,site,862);
    for (i = 0; i < n; i++) {
        u16 id;
        id = ids[i];
        if (map[id] != 999) {
            result[used] = id;
            used++;
        }
    }
    release(ids);
    release(map);
    *out = result;
    return count;
}
