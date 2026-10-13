/*
 * function: NHTTP_Startup
 * address:  0x021BE648
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_Startup  0x021BA88C  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *
 *
 * Keyed unlink: 0 when the record was freed, -1 when it was absent.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern int NHTTPi_Startup(void *sysInfo_p, void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio);

int NHTTP_Startup(int a, int b, int c)
{
    return -(NHTTPi_Startup(NHTTPi_GetSystemInfoP(), (void * (*)(long unsigned int,  int))a, (void (*)(void *))b, c) == 0);
}
