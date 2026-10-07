/*
 * file:     unit_0218F9F8_p02.c
 * unit:     yes
 * function: func_0218FDD8, func_0218FEF0, func_0218FF24
 * address:  0x0218FDD8
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
 *   func_0219329C  0x0219329c  arm   ov009
 *   func_020949F4  0x020949f4  arm
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189d78  arm   ov009
 *   func_0217EAB0  0x0217eab0  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_02189DFC  0x02189dfc  arm   ov009
 *   func_0218E240  0x0218e240  arm   ov009
 *   g_021A5224     0x021a5224  data
 *   g_021A51D8     0x021a51d8  data
 *   g_021A5214     0x021a5214  data
 *   gpiGetProfile                    0x0218FD9C arm
 *   TableRemove                      0x021847BC arm
 *   func_021847BC  0x021847BC  arm
 */
struct GPIOperation;
struct GPIProfile;
typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPIOperation_s {
    int type;
    void *data;
    int blocking;
    GPICallback callback;
} GPIOperation;

typedef struct {
    int result;
    int profile;
} GPDeleteProfileResponseArg;

typedef struct {
    char pad[0x1a0];
    int profileid;
} GPIConnection_0218FDD8;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct GPIConnection_0218FEF0
{
	char pad[0x5C8];
	void * profiles;
} GPIConnection_0218FEF0;

extern int func_0219329C(int *connection, const char *input, int fatal);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(int *p, int b);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void func_0218E240(void **connection, struct GPIOperation *operation);
extern int gpiGetProfile(void ** connection, int profileid, struct GPIProfile ** pProfile);
extern int TableRemove(void * table, void * delElem);
extern void func_021847BC(int v);
int func_0218FDD8(void **connection, GPIOperation *operation, char *input);
void gpiRemoveProfileByID(void ** connection, int profileid);
void func_0218FF24(const int *p, void *profile);
extern char g_021A5224[];
extern char g_021A51D8[];
extern char g_021A5214[];


/*
 * sdk:      gpiProcessDeleteProfle (libdwcgsgp.TWL.HYB.a gpiprofile.o)
 */
int func_0218FDD8(void **connection, GPIOperation *operation, char *input)
{
    GPIConnection_0218FDD8 *iconnection = (GPIConnection_0218FDD8 *)*connection;
    GPICallback callback;
    GPDeleteProfileResponseArg *arg;
    int __result__;

    if (func_0219329C((int *)connection, input, 1))
        return 4;
    if (func_020949F4((const u8 *)input, (const u8 *)g_021A5224, 5) != 0) {
        func_02193710((int *)connection, 1, (int)g_021A51D8);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }
    callback = operation->callback;
    if (operation->callback.callback != 0) {
        arg = (GPDeleteProfileResponseArg *)func_0217EAB0(sizeof(GPDeleteProfileResponseArg));
        if (arg == 0) {
            func_02193734((int *)connection, (int)g_021A5214);
            return 1;
        }
        arg->profile = iconnection->profileid;
        arg->result = 0;
        __result__ = func_02189DFC(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    func_0218E240(connection, (struct GPIOperation *)operation);
    return 0;
}


void gpiRemoveProfileByID(void ** connection, int profileid)
{
	GPIConnection_0218FEF0 * iconnection = (GPIConnection_0218FEF0 *)*connection;
	struct GPIProfile * profile;

	if (gpiGetProfile(connection, profileid, &profile))
		TableRemove(iconnection->profiles, profile);
}


/*
 * Tail call on the word at +0x5c8 of the block the object points at.
 */
void func_0218FF24(const int *p, void *profile)
{
    func_021847BC(*(const int *)(*p + 0x5c8));
}
