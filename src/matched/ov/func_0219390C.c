/*
 * function: FIELD_WFBC_GetPeople
 * address:  0x0219390C
 * packet:   pkt_0219390C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_WFBC_FindPeopleByNpcId  0x02193F34  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct E50;
struct V;
extern struct E50 *FIELD_WFBC_FindPeopleByNpcId(struct V *v, u32 key);

void *FIELD_WFBC_GetPeople(void *a, u32 b)
{
if (b < 30) {
    return FIELD_WFBC_FindPeopleByNpcId(a, b);
}
return 0;
}

