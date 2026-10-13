/*
 * function: NAMEIN_SETUP_CreateCaptureArgs
 * address: 0x0216C0A4
 * packet: pkt_ov010_0216C0A4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_SETUP_CreateMonArgs 0x0216C028 thumb ov010
 */
extern int *NAMEIN_SETUP_CreateMonArgs(unsigned short, int, int, int, int);
int *NAMEIN_SETUP_CreateCaptureArgs(unsigned short a, int b, int c, int d, int e, int f, int g, int h) {
    int *p;
    p = NAMEIN_SETUP_CreateMonArgs(a,b,c,d,h);
    p[3]=e; p[4]=f; p[5]=g;
    return p;
}
