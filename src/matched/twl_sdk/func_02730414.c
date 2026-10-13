/*
 * function: MI_GetWramMapStart
 * address:  0x02730414
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_027301EC 0x027301EC data twl
 */
typedef unsigned int u32;

extern u32 (*const data_027301EC[])(void);

u32 MI_GetWramMapStart(u32 i)
{
    return data_027301EC[i]();
}
