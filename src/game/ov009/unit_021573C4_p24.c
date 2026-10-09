/*
 * file:     unit_021573C4_p24.c
 * unit:     yes
 * function: func_0215AB10, func_0215AB5C, func_0215AB7C, func_0215AB94, func_0215ABB0, func_0215AC60, func_0215ACA0
 * address:  0x0215AB10
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
 *   g_02150FEC  0x02150FEC  data
 *   func_02082BCC  0x02082BCC  arm
 *   func_0215AA18  0x0215AA18  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   func_021593A8  0x021593A8  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A826C  0x021A826C  data
 *   func_02162968  0x02162968  arm  ov009
 *   OS_YieldThread                   0x020858d8 arm
 *   OS_DisableInterrupts             0x02087988 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   _tcp_send_finack                 0x02159494 arm
 *   _tcp_send_ack                    0x02159404 arm
 */
struct CPSSoc;
struct Soc;
struct NetVars {
	unsigned char pad0[0x50];
	unsigned long myip;
};

struct Soc {
	unsigned char pad0[4];
	unsigned long block_type;
	unsigned char state;
	unsigned char pad1[7];
	unsigned long when;
	unsigned char pad2[0x20];
	unsigned long seqno;
};

struct _CPSSoc {
	unsigned char pad[8];
	unsigned char state;
};

extern void func_02082BCC(void *dst, unsigned char data, unsigned long size);
extern unsigned long func_0215AA18(void);
extern unsigned long long func_020870D0(void);
extern void func_021593A8(char *soc, unsigned char flag);
extern unsigned long func_02087988(void);
extern void func_020857B0(void *queue);
extern unsigned long func_0208799C(unsigned long state);
extern unsigned long func_02162968(struct CPSSoc *soc);
extern void OS_YieldThread(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void _tcp_send_finack(struct _CPSSoc *soc);
extern void _tcp_send_ack(struct _CPSSoc *soc, int flush);
void func_0215AB10(void);
void func_0215AB5C(void);
asm void CPS_SocDup(void);
asm void CPS_SetUdpCallback(void);
unsigned long func_0215ABB0(struct Soc *soc);
unsigned long func_0215AC60(void);
void CPSi_TcpShutdownRaw(struct _CPSSoc *soc);
extern char g_02150FEC[];
extern struct NetVars g_021A826C;


/*
 * sdk:      CPS_SocUse (libcps.TWL.HYB.a(network.o))
 */
void func_0215AB10(void)
{
    char *cur = *(char **)(g_02150FEC + 4);
    char *soc = *(char **)(cur + 0xa4);

    if (soc == 0)
        return;
    *(char **)soc = cur;
    *(unsigned char *)(soc + 8) = 0;
    *(unsigned long *)(soc + 0x50) = 0;
    func_02082BCC(soc + 0x70, 0, 0x30);
    *(unsigned long *)(soc + 0x6c) = 0;
    *(unsigned long *)(soc + 0x44) = 0;
    *(unsigned char *)(soc + 0x33) = 0;
}


/*
 * Clears the word the object at +0xa4 points to, when it is there.
 */
void func_0215AB5C(void)
{
    char *p = *(char **)(g_02150FEC + 4);
    int *q = *(int **)(p + 0xa4);

    if (q) {
        *q = 0;
    }
}

asm void CPS_SocDup(void)
{
	ldr r1, =0x02150FEC
	ldr r1, [r1, #4]
	ldr r1, [r1, #0xa4]
	str r1, [r0, #0xa4]
	bx lr
}

asm void CPS_SetUdpCallback(void)
{
	ldr r1, =0x02150FEC
	ldr r1, [r1, #4]
	ldr r1, [r1, #0xa4]
	cmp r1, #0
	strne r0, [r1, #0x44]
	bx lr
}


/*
 * sdk:      CPSi_TcpConnectRaw (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215ABB0(struct Soc *soc)
{
	unsigned long retry;
	unsigned long seqno;
	unsigned long enabled;

	seqno = func_0215AA18();
	for (retry = 0; retry < 3; retry++) {
		soc->seqno = seqno;
		soc->state = 2;
		soc->when = (unsigned long)(func_020870D0() >> 16);
		func_021593A8((char *)soc, 2);
		enabled = func_02087988();
		if (soc->state == 2 && g_021A826C.myip != 0) {
			soc->block_type = 1;
			func_020857B0(0);
		}
		func_0208799C(enabled);
		if (soc->state == 4)
			return 0;
		if (g_021A826C.myip == 0)
			break;
	}
	return 1;
}


/*
 * sdk:      CPS_TcpConnect (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215AC60(void)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 9) != 0)
            return func_02162968((struct CPSSoc *)soc);
        return func_0215ABB0((struct Soc *)soc);
    }
    return 1;
}


void CPSi_TcpShutdownRaw(struct _CPSSoc *soc)
{
	unsigned long enable;
	unsigned char state;

	OS_YieldThread();
	enable = OS_DisableInterrupts();
	state = soc->state;
	if ((unsigned char)(state + 0xfd) <= 1) {
		soc->state = 7;
		OS_RestoreInterrupts(enable);
		_tcp_send_finack(soc);
	} else if (state != 0) {
		OS_RestoreInterrupts(enable);
		_tcp_send_ack(soc, 2);
	} else {
		OS_RestoreInterrupts(enable);
	}
}
