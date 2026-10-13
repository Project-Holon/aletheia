/*
 * file:     message.c
 * unit:     yes
 * function: func_021C0F60, func_021C0F98, func_021C0FAC, func_021C1004, func_021C1030, func_021C1048
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5410  0x021D5410  arm  ov016
 *   g_021DE58C  0x021DE58C  data
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_021D4B68  0x021D4B68  arm  ov016
 *   func_021D4C68  0x021D4C68  arm  ov016
 *   func_021D546C  0x021D546C  arm  ov016
 */
#include "../../matched/include/G_MemMsg.h"

typedef struct {
	int a;
	int b;
	int c;
} Info;

typedef struct MemMsg MemMsg;

typedef struct MsgPrm {
    unsigned int *index;
    unsigned char *data;
} MsgPrm;

extern void *func_021D6414(unsigned long size, int align);
extern void *func_021D5410(long size, void *data, long dsize);
extern void func_021D6438(void **mem);
extern void *func_021D54C4(void *que);
extern void *func_021D4B68(char *path, unsigned long *size, int alignment);
extern void func_021D4C68(void *file);
extern void func_021D546C(void *queue, void *data);
void func_021C0F60(void);
void func_021C0F98(void);
void *func_021C0FAC(char *file);
void func_021C1004(void *msg);
unsigned int func_021C1030(unsigned int *p, unsigned int idx);
unsigned short *func_021C1048(void *msg, int id, int n, int num);
extern struct MemMsg *g_021DE58C;


/*
 * sdk:      DWCi_MSGlInit (libdwcutil.TWL.HYB.a(message.o))
 */
void func_021C0F60(void)
{
	void *m = func_021D6414(0x64, 4);
	g_021DE58C = m;
	*(void **)(((char *)g_021DE58C) + 0x60) = func_021D5410(8, m, 0xc);
}


/*
 * Tail-call func_021D6438 with the address of 0x021DE58C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0F98.c \
 *       --func func_021C0F98 --addr 0x021C0F98 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0F98(void)
{
    func_021D6438((void *)0x021DE58C);
}


/*
 * sdk:      DWCi_MSGlRead (libdwcutil.TWL.HYB.a(message.o))
 */
void *func_021C0FAC(char *file)
{
	unsigned long size;
	Info *info;
	char *msg;
	int *hdr;

	info = (Info *)func_021D54C4(*(void **)(((char *)g_021DE58C) + 0x60));
	msg = func_021D4B68(file, &size, 4);
	hdr = (int *)(msg + 0x20);
	info->c = (int)msg;
	info->a = (int)(hdr + 4);
	info->b = (int)hdr + hdr[1] + 8;
	return info;
}


/*
 * sdk:      DWCi_MSGlRelease (libdwcutil.TWL.HYB.a message.o)
 */
void func_021C1004(void *msg)
{
    func_021D4C68(((void **)msg)[2]);
    func_021D546C(g_021DE58C->queue, msg);
}

/*
 * Word of the table at p[0], indexed by the low halfword, plus the p[1] base.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C1030.c \
 *       --func func_021C1030 --addr 0x021C1030 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned int func_021C1030(unsigned int *p, unsigned int idx)
{
    return p[1] + ((unsigned int *)p[0])[(unsigned short)idx];
}


/*
 * sdk:      DWCi_MSGlGetEx (libdwcutil.TWL.HYB.a message.o)
 */
unsigned short *func_021C1048(void *msg, int id, int n, int num)
{
    MsgPrm *ms = msg;
    unsigned short *str = (unsigned short *)(ms->data + ms->index[(unsigned short)id]);
    if (n >= 0)
        str[n] = num + 0x30;
    return str;
}
