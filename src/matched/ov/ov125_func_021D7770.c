/*
 * function: GDS_SOCKET_Start
 * address: 0x021D7770
 * packet: pkt_ov125_021D7770
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   gGdsHostTail 0x021DA040 data a4
 *   GDS_SOCKET_NopBegin 0x021D8588 arm ov125
 *   GDS_SOCKET_InitTick 0x021D7CF4 arm ov125
 *   GDS_SOCKET_InitLock 0x021D7CD4 arm ov125
 *   GDS_SOCKET_ResetConnection 0x021D7808 arm ov125
 *   strcpy  0x02094798  arm  arm9
 */
typedef struct { int words[78]; } Record;
typedef struct { Record record; int f138; char pad13c[4]; char name[256]; char pad240[24]; int f258; char pad25c[16]; int f26c; } State;
extern State gGdsSocket;
extern char gGdsHostTail[];
extern void GDS_SOCKET_NopBegin(void);
extern int GDS_SOCKET_InitTick(void);
extern int GDS_SOCKET_InitLock(void);
extern char *strcpy(char *, const char *);
extern void GDS_SOCKET_ResetConnection(void);
static inline Record *copy(Record *dst, const Record *src) { *dst = *src; return dst; }
int GDS_SOCKET_Start(const char *a, unsigned short b, Record *src)
{
    if (src) {
        gGdsSocket.record = *src;
        gGdsSocket.f138 = 0;
    }
    GDS_SOCKET_NopBegin();
    if (!GDS_SOCKET_InitTick()) return 0;
    GDS_SOCKET_InitLock();
    strcpy(gGdsSocket.name, a);
    *(short *)(gGdsHostTail + 0x40) = b;
    gGdsSocket.f258 = 0;
    gGdsSocket.f26c = -1;
    GDS_SOCKET_ResetConnection();
    return 1;
}
