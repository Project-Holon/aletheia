/*
 * function: func_021C1804
 * address:  0x021C1804
 * packet:   pkt_ov114_021C1804
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiTwlSSLInit (libdwcgsghttp.TWL.HYB.a ghttpencryption.o)
 *
 * symbols:
 *   func_021C1230  0x021c1230  arm   ov114
 *   func_02088168  0x02088168  arm
 *   func_02162248  0x02162248  arm   ov009
 *   func_0217EAB0  0x0217eab0  arm   ov009
 *   func_020923B0  0x020923b0  arm
 *   func_0217D254  0x0217d254  arm   ov009
 *   g_021D3B44     0x021d3b44  data  ov114
 *   func_021C1668  0x021c1668  arm   ov114
 *   g_021CE7B0     0x021ce7b0  data
 *   g_021CE678     0x021ce678  data  ov114
 *   g_021CEA74     0x021cea74  data  ov114
 *   g_021CEAB4     0x021ceab4  data  ov114
 */

typedef struct GHTTPTwlCaList {
    void *certs;
    int count;
} GHTTPTwlCaList;

typedef struct CPSSslConnection {
    char pad0[0x800];
    int f800;
    char pad1[0x810 - 0x804];
    int (*f810)(int, void *, int);
    void *f814;
    int f818;
    char pad2[0x830 - 0x81c];
} CPSSslConnection;

extern void *func_021C1230(char *url);
extern void func_02088168(unsigned long *);
extern void func_02162248(void *, unsigned long);
extern void *func_0217EAB0(unsigned long);
extern void *func_020923B0(void *, int, unsigned long);
extern void func_0217D254(int, int, unsigned char, const char *, ...);
extern int func_021C1668(int, void *, int);
extern unsigned long g_021D3B44[8];
extern char g_021CE7B0[];
extern char g_021CE678[];
extern char g_021CEA74[];
extern char g_021CEAB4[];

CPSSslConnection *func_021C1804(char *url)
{
    GHTTPTwlCaList *rootCaList;
    CPSSslConnection *sslCon = 0;

    rootCaList = func_021C1230(url);
    if (rootCaList != 0) {
        if (rootCaList->certs != 0 && rootCaList->count > 0) {
            func_02088168(g_021D3B44);
            func_02162248(g_021D3B44, 0x20);
            sslCon = func_0217EAB0(0x830);
            if (sslCon != 0) {
                func_020923B0(sslCon, 0, 0x830);
                sslCon->f800 = 0;
                sslCon->f814 = rootCaList->certs;
                sslCon->f818 = rootCaList->count;
                sslCon->f810 = func_021C1668;
            } else {
                func_0217D254(8, 2, 2, g_021CEA74, g_021CE7B0, g_021CE678, 0x3fc);
            }
        } else {
            func_0217D254(8, 2, 2, g_021CEAB4, g_021CE7B0, g_021CE678, 0x403);
        }
    } else {
        func_0217D254(8, 2, 2, g_021CEAB4, g_021CE7B0, g_021CE678, 0x40a);
    }
    return sslCon;
}
