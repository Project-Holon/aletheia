/*
 * function: func_021BE468
 * address:  0x021BE468
 * packet:   pkt_ov172_021BE468
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss, 31 bytes, register and pool order)
 *
 * sdk:      Mel_JPEGDecodeExif (libssp.TWL.HYB.a jpegdec.o)
 *
 * symbols:
 *   func_02082AC0  0x02082AC0  arm
 *   func_021C0BB4  0x021C0BB4  arm  ov172
 *   g_021C88F0     0x021C88F0  data
 *   g_021C8D1C     0x021C8D1C  data ov172
 *   g_021C8C1C     0x021C8C1C  data ov172
 *   g_021C8B1C     0x021C8B1C  data ov172
 *   g_021C959C     0x021C959C  data ov172
 *
 * Static: clears the decoder state, validates the SOI marker and walks the marker segments until the APP1 (Exif) segment, which SSP_ExifDecode parses.
 */

typedef struct {
    int byte;
    unsigned int pad0;
    unsigned int length;
    unsigned int esc;
    unsigned int bits;
} BitState;

extern BitState g_021C88F0;
extern short g_021C8D1C[];
extern short g_021C8C1C[];
extern short g_021C8B1C[];
extern unsigned char g_021C959C[];
extern void func_02082AC0(unsigned long data, void *destp, unsigned long size);
extern long func_021C0BB4(unsigned char *src, unsigned long src_size, int *cur, int option);

int func_021BE468(unsigned char *a, unsigned long length, int option)
{
    int p;
    int s;
    unsigned char b;
    long result;

    g_021C88F0.esc = 0;
    g_021C88F0.bits = 0;
    g_021C8D1C[0] = 0;
    g_021C8C1C[0x40] = 0;
    g_021C8B1C[0] = 0;
    func_02082AC0(0, g_021C959C, 0x1000);
    g_021C88F0.length = length;
    if (length <= 2) return 0;
    if (a[0] != 0xFF || a[1] != 0xD8) return 0;
    p = 2;
    while ((unsigned long)(p + 1) < length) {
        s = a[p++];
        if (s == 0xFF) {
            b = a[p++];
            if (b == 0xD9) break;
            if ((unsigned long)(p + 1) >= length) return 0;
            s = (a[p] << 8) | a[p + 1];
            if (b == 0xE1) {
                result = func_021C0BB4(a, length, &p, option);
                if (result != 0 && result != 1) return 0;
                break;
            }
            p += s;
        }
    }
    return -(p <= g_021C88F0.length);
}
