/*
 * file:     unit_021573C4_p18.c
 * unit:     yes
 * function: func_021595C0, func_021596A8
 * address:  0x021595C0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   func_021592A8  0x021592A8  arm  ov009
 *   func_021593A8  0x021593A8  arm  ov009
 *   func_02159244  0x02159244  arm  ov009
 *   func_021594A4  0x021594A4  arm  ov009
 */
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))
struct _CPSSoc;
struct _CPSSoc {
	unsigned char pad0[8];
	unsigned char state;
	unsigned char pad1[7];
	unsigned long seqno;
	unsigned long local_ip;
	unsigned short remote_port;
	unsigned char pad2[2];
	unsigned long remote_ip;
	unsigned char pad3[4];
	unsigned long ackno;
};

extern unsigned long long func_020870D0(void);
extern void func_021592A8(unsigned char *tcphdr, struct _CPSSoc *soc);
extern void func_021593A8(char *soc, unsigned char flag);
extern char *func_02159244(unsigned char *iphdr, unsigned char *tcphdr);
extern void func_021594A4(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
void func_021595C0(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
unsigned long func_021596A8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);


/*
 * sdk:      dt_syn_LISTEN (libcps.TWL.HYB.a(network.o))
 */
void func_021595C0(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc)
{
	soc->state = 3;
	soc->seqno = (unsigned long)(func_020870D0() >> 16);
	soc->local_ip = BE32(iphdr, 0x10);
	soc->remote_port = SWAP16(*(unsigned short *)tcphdr);
	soc->remote_ip = BE32(iphdr, 0xc);
	soc->ackno = BE32(tcphdr, 4) + 1;
	func_021592A8(tcphdr, soc);
	func_021593A8((char *)soc, 0x12);
}


/*
 * sdk:      find_specific_socket (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_021596A8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
    char *soc = func_02159244(iphdr, tcphdr);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 1) {
            func_021595C0(iphdr, tcphdr, (struct _CPSSoc *)soc);
        } else if (*(unsigned char *)(soc + 8) == 3) {
            *(long *)(soc + 0x34) = *(long *)(soc + 0x34) - 1;
            func_021595C0(iphdr, tcphdr, (struct _CPSSoc *)soc);
        } else {
            func_021594A4(iphdr, tcphdr, len);
        }
        return 1;
    }
    return 0;
}
