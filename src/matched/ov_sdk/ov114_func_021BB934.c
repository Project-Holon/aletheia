/*
 * function: NHTTPi_destroyRequestObject
 * address:  0x021BB934
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_free  0x021BA850  arm  ov114
 *   deleteStrList  0x021BB8F0  arm  ov114
 *   NHTTPi_Request2Connection  0x021BEBE0  arm  ov114
 *
 *
 * Releases the record's four handles plus the record itself, then clears the +0x10 slot of the module view.
 */

typedef unsigned char u8;
typedef unsigned int u32;
u8 *NHTTPi_Request2Connection(int, int);
struct List;
void deleteStrList(struct List *list_p);
void NHTTPi_free(int a);

int NHTTPi_destroyRequestObject(int a, u8 *b)
{
    u8 *p = NHTTPi_Request2Connection(a, (int)b);

    if (p != 0)
        *(u32 *)(p + 0x10) = 0;
    deleteStrList((struct List *)(*(u32 *)(b + 0x30)));
    deleteStrList((struct List *)(*(u32 *)(b + 0x34)));
    NHTTPi_free(*(u32 *)(b + 0x24));
    NHTTPi_free(*(u32 *)(b + 0x28));
    NHTTPi_free((u32)b);
    return 1;
}
