# Original bugs and mismatches

The DS build (`__MWERKS__`) is the original code, unchanged and byte-exact. Some original code is
not correct C: it falls off the end of a function, calls a function with a different prototype, or
reads the result of a void function. The host (PC) build must do what the DS does at run time.

Rule: guard a case only if the PC build can give a different result with the code unchanged.
Otherwise keep the code and write a row in `docs/ORIGINAL_BUGS.tsv` with "host: same" and the reason.
Every case has a row in that file (kind, file:line, function, DS behaviour, host behaviour).

## Kinds

A. Missing return. The function falls off the end, so r0 holds some leftover value. The host
register holds something else, so the code returns the DS value at that point:

    #ifndef __MWERKS__
        return rate; /* the DS leaves the argument in r0 */
    #endif

   If the leftover is the result of a void call, the host returns 0.

B. Narrow return or argument. The caller declares a narrower type than the definition. Both
ABIs truncate to the caller's width, so the host is usually the same: no guard. If both
declarations meet in one file, keep the original declaration under `__MWERKS__` and the header
under the host branch, as in `ov009/wcm_system.c` (`WCMi_NwmifGetAllowedChannel`).

C. Void read. A caller reads the result of a function defined void. First give the definition its
real return type; if every file stays EXACT, no guard is needed (`POKEGRA_RegisterTrainerCgr`).
Otherwise the host calls with the value r0 holds on the DS, guarded at the call.

D. Declaration mismatch. Extra arguments are ignored by the callee on both builds: same. Missing
arguments differ: the host call passes the definition's arguments, the DS keeps the original call.

E. Gameplay bug. The DS and the host behave the same, so both keep it. The fixed form goes under
`#ifdef BUGFIX` with a one-line comment that says what the bug is.

Call casts through a function pointer type are not used to hide a mismatch: fix the type, or use
one guarded declaration block at the top of the file, as in `ov009/dwc_transport.c`.
