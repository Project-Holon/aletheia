/*
 * file:     unit_0215CD3C_p03.c
 * unit:     yes
 * function: func_0215CEB0, func_0215CEFC, func_0215CF14
 * address:  0x0215CEB0
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
 *   func_02085DBC  0x02085DBC  arm
 *   func_0215CE7C  0x0215CE7C  arm  ov009
 *   func_0215CE9C  0x0215CE9C  arm  ov009
 *   func_02085D94  0x02085D94  arm
 *   func_02085E50  0x02085E50  arm
 */
struct OSMessageQueue;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
	unsigned char pad0[0x20];
} MsgQueue;

typedef struct {
	unsigned long pad0;
	unsigned long pad1;
	MsgQueue *response_queue;
	unsigned char pad2;
	signed char flag_block;
} Command;

typedef signed int     s32;

int func_02085DBC(int a0, char *a1, int r2);
void func_0215CE7C(void *ptr);
extern int func_0215CE9C(const int *p, int b);
extern void func_02085D94(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern int func_02085E50(MsgQueue *mq, void **msg, long flags);
int func_0215CEB0(int a0, char *a1);
void func_0215CEFC(int a, int b);
int func_0215CF14(void *pipe, Command *command);


/*
 * Runs one helper with a flag derived from bit 0 of the object's byte 0xd
 * (defaulting to 1 for a null object); on a zero result runs a teardown and
 * returns -0x29, otherwise 0.
 */
int func_0215CEB0(int a0, char *a1)
{
    int r2;
    int r4;

    if (a1 == 0 || (a1[0xd] & 1))
        r2 = 1;
    else
        r2 = 0;
    r4 = func_02085DBC(a0, a1, r2);
    if (r4 == 0)
        func_0215CE7C(a1);
    return r4 ? 0 : -0x2A;
}


/*
 * Passes the second argument on to both calls.
 */
void func_0215CEFC(int a, int b)
{
    int v = func_0215CE9C((const int *)a, b);

    func_0215CEB0(v, (char *)b);
}


/*
 * sdk:      SOCLi_ExecCommandPacket (libsoc.TWL.HYB.a(socl_command.o))
 */
int func_0215CF14(void *pipe, Command *command)
{
	long result;
	void *response;
	MsgQueue response_queue;

	if (command->flag_block == 1) {
		func_02085D94((struct OSMessageQueue *)(&response_queue), &response, 1);
		command->response_queue = &response_queue;
		func_0215CEB0((int)pipe, (char *)command);
		func_02085E50(&response_queue, (void **)&result, 1);
	} else {
		command->response_queue = 0;
		result = func_0215CEB0((int)pipe, (char *)command);
	}
	return result;
}
