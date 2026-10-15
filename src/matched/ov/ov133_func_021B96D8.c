/*
 * function: func_021B96D8
 * address: 0x021B96D8
 * packet: pkt_ov133_021B96D8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_SAVE_GetOutfits 0x0200A628 thumb
 *   MUSICAL_SAVE_InitOutfits 0x0200A604 thumb
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb
 *   func_021BA184 0x021BA184 thumb
 *   func_021BA258 0x021BA258 thumb
 *   func_021BA20C 0x021BA20C thumb
 *   func_021BA208 0x021BA208 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Big;
extern u8 *MUSICAL_SAVE_GetOutfits(struct Big *p);
extern void MUSICAL_SAVE_InitOutfits(struct Big *p);
extern char *MUSICAL_MCSS_GetRenderElem(char *, int);
extern void *func_021BA184(char *p);
extern u32 func_021BA258(char *p);
extern u32 func_021BA20C(u8 *p);
extern u32 func_021BA208(u8 *p);
void func_021B96D8(char *p)
{
    u8 *sv = MUSICAL_SAVE_GetOutfits(*(void **)(*(char **)(p + 4) + 8));
    void *t;
    u8 i = 0;
    MUSICAL_SAVE_InitOutfits(*(void **)(*(char **)(p + 4) + 8));
    t = func_021BA184(*(char **)(p + 0x1824));
    while (t != 0 && i < 8) {
        u32 idx = (u16)func_021BA258(t);
        u8 *rec;
        u32 off;
        MUSICAL_MCSS_GetRenderElem(*(char **)(p + 0x1880), idx);
        rec = sv + i * 6;
        sv[i * 6] = idx;
        *(u16 *)(rec + 2) = *((u16 *)func_021BA20C(t));
        off = idx * 6;
        *(s16 *)(rec + 4) = *(s16 *)(*(char **)(*(char **)(p + 4) + 4) + off + 0x16);
        *(u16 *)(*(char **)(*(char **)(p + 4) + 4) + off + 0x14) = *((u16 *)func_021BA20C(t));
        *(u8 *)(*(char **)(*(char **)(p + 4) + 4) + off + 0x18) = i;
        t = (void *)func_021BA208(t);
        i++;
    }
}
