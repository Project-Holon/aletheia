/*
 * file:     unit_0206B780.c
 * unit:     yes
 * function: func_0206B780, func_0206B7A8
 * address:  0x0206B780
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

/* Record with a callback at +0x0C and a call counter at +0x00. */
typedef struct CountedCallback CountedCallback;

struct CountedCallback {
    u32   callCount;
    u32   unused04;
    u32   unused08;
    void (*callback)(void *);
};

/* Record with a callback at +0x10 and a status word at +0x08. */
typedef struct FlaggedCallback FlaggedCallback;

struct FlaggedCallback {
    u32   unused00;
    u32   unused04;
    u32   status;
    u32   unused0c;
    void (*callback)(void *);
};

#define CALLBACK_STATUS_DONE 0x20

void func_0206B780(CountedCallback *pRecord);
void func_0206B7A8(FlaggedCallback *pRecord);


/*
 * Calls the callback at +0x0C when it is set, handing it the object itself
 * (which is why the pointer is loaded into r1 and never r0), then bumps the
 * counter at +0x00.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206B780.c \
 *       --func func_0206B780 --addr 0x0206B780 --cc 1.1p1 --arm
 */
void func_0206B780(CountedCallback *pRecord)
{
    if (pRecord->callback != 0) {
        pRecord->callback(pRecord);
    }
    pRecord->callCount++;
}


/*
 * Same shape as func_0206B780 one slot over: the callback at +0x10 is handed
 * the object itself, then bit 5 of the status word at +0x08 is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206B7A8.c \
 *       --func func_0206B7A8 --addr 0x0206B7A8 --cc 1.1p1 --arm
 */
void func_0206B7A8(FlaggedCallback *pRecord)
{
    if (pRecord->callback != 0) {
        pRecord->callback(pRecord);
    }
    pRecord->status |= CALLBACK_STATUS_DONE;
}
