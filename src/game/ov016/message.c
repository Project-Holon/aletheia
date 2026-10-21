/*
 * file:     message.c
 * unit:     yes
 * function: DWCi_MSGlInit, DWCi_MSGlEnd, DWCi_MSGlRead, DWCi_MSGlRelease, DWCi_MSGlGet, DWCi_MSGlGetEx
 * address:  0x021C0F60
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_HEAPlFree_                0x021D6438  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   gMessageWork  0x021DE58C  data
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   DWCi_ARClReadEx  0x021D4B68  arm  ov016
 *   DWCi_ARClRelease  0x021D4C68  arm  ov016
 *   DWCi_QUElPushBack  0x021D546C  arm  ov016
 */
struct MemMsg {
    unsigned char pad_0[0x60];
    void *queue;
};

typedef struct MemMsg MemMsg;

typedef struct MsgPrm {
    unsigned int *index;
    unsigned char *data;
    void *raw;
} MsgPrm;

#include "heap.h"
#include "deque.h"
#include "archive.h"
void DWCi_MSGlInit(void);
void DWCi_MSGlEnd(void);
void *DWCi_MSGlRead(char *file);
void DWCi_MSGlRelease(void *msg);
unsigned short *DWCi_MSGlGet(MsgPrm *p, unsigned int idx);
unsigned short *DWCi_MSGlGetEx(void *msg, int id, int n, int num);
extern struct MemMsg *gMessageWork;


/*
 * sdk:      DWCi_MSGlInit (libdwcutil.TWL.HYB.a(message.o))
 */

void DWCi_MSGlInit(void)
{
	void *m = DWCi_HEAPlAllocEx(0x64, 4);
	gMessageWork = m;
	*(void **)(((char *)gMessageWork) + 0x60) = DWCi_QUElFormEx(8, m, 0xc);
}


/*
 * Tail-call DWCi_HEAPlFree_ with the address of 0x021DE58C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MSGlEnd.c \
 *       --func DWCi_MSGlEnd --addr 0x021C0F98 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_MSGlEnd(void)
{
    DWCi_HEAPlFree_((void *)0x021DE58C);
}


/*
 * sdk:      DWCi_MSGlRead (libdwcutil.TWL.HYB.a(message.o))
 */
void *DWCi_MSGlRead(char *file)
{
	unsigned long size;
	MsgPrm *info;
	char *msg;
	int *hdr;

	info = (MsgPrm *)DWCi_QUElPopBack(*(void **)(((char *)gMessageWork) + 0x60));
	msg = DWCi_ARClReadEx(file, &size, 4);
	hdr = (int *)(msg + 0x20);
	info->raw = msg;
	info->index = (unsigned int *)(hdr + 4);
	info->data = (unsigned char *)hdr + hdr[1] + 8;
	return info;
}


/*
 * sdk:      DWCi_MSGlRelease (libdwcutil.TWL.HYB.a message.o)
 */
void DWCi_MSGlRelease(void *msg)
{
    DWCi_ARClRelease(((void **)msg)[2]);
    DWCi_QUElPushBack(gMessageWork->queue, msg);
}

/*
 * Word of the table at p[0], indexed by the low halfword, plus the p[1] base.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_MSGlGet.c \
 *       --func DWCi_MSGlGet --addr 0x021C1030 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned short *DWCi_MSGlGet(MsgPrm *p, unsigned int idx)
{
    return (unsigned short *)(p->data + p->index[(unsigned short)idx]);
}


/*
 * sdk:      DWCi_MSGlGetEx (libdwcutil.TWL.HYB.a message.o)
 */
unsigned short *DWCi_MSGlGetEx(void *msg, int id, int n, int num)
{
    MsgPrm *ms = msg;
    unsigned short *str = (unsigned short *)(ms->data + ms->index[(unsigned short)id]);
    if (n >= 0)
        str[n] = num + 0x30;
    return str;
}
