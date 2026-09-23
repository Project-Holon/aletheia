#!/usr/bin/env python3
"""Host environment discovery shared by every tool in tools/ (stdlib only).

One place answers "where is X on this machine" so that no tool hardcodes a
checkout path, a scratch path, a shell or an absolute toolchain path.  The
same code runs on Windows, macOS and Linux.

    ROOT                      repo root, from this file's own location
    PYTHON                    the running interpreter (sys.executable)
    arm_toolchain(explicit)   (bindir, source) of arm-none-eabi binutils
    mwcc_dir()                tools/mwccarm/mwccarm (dsi/<version>/ below it)
    mwcc_exe(version)         path of one mwccarm.exe
    windows_cmd(cmd)          cmd, prefixed with wine/wine64 off Windows
    host_tool(name)           gcc / g++ / cmake / ninja for the eidos port
    scratch_dir(*sub)         ALETHEIA_SCRATCH, else <tempdir>/aletheia

Resolution orders
-----------------
ARM binutils: --toolchain argument, BW_ARM_TOOLCHAIN, tools/gcc-arm/bin,
tools/gcc-arm/*/bin, then PATH.  A candidate counts only if it holds
arm-none-eabi-as.
CodeWarrior runner: the .exe itself on Windows; elsewhere wine64, then wine,
found on PATH (EnvError naming both if neither exists).
Host toolchain: tools/gcc-host/*/bin, tools/cmake/*/bin (also the macOS
CMake.app layout), tools/ninja, then PATH.

``python tools/env.py`` prints what it resolved.
"""

from __future__ import annotations

import glob
import os
import shutil
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.path.join(ROOT, "tools")
PYTHON = sys.executable
IS_WINDOWS = sys.platform == "win32"


class EnvError(Exception):
    """Something a tool needs is not installed where it could be found."""


def repo_path(*parts):
    """Join repo-relative parts onto ROOT.  Accepts "a/b" style parts too."""
    out = ROOT
    for p in parts:
        out = os.path.join(out, *p.replace("\\", "/").split("/"))
    return out


def _which_in(name, bindir):
    """shutil.which restricted to one directory (honours PATHEXT on Windows)."""
    return shutil.which(name, path=bindir) if bindir else shutil.which(name)


# ---------------------------------------------------------------------------
# ARM binutils (arm-none-eabi-as, -ld, -objcopy)
# ---------------------------------------------------------------------------

ARM_PREFIX = "arm-none-eabi-"


def arm_toolchain_candidates(explicit=None):
    """Every place an ARM bin directory may live, in priority order, as
    (bindir or None for PATH, source label).  Unchecked."""
    cands = []
    if explicit:
        cands.append((explicit, "--toolchain"))
    envdir = os.environ.get("BW_ARM_TOOLCHAIN")
    if envdir:
        cands.append((envdir, "BW_ARM_TOOLCHAIN"))
    local = os.path.join(TOOLS, "gcc-arm")
    for d in [os.path.join(local, "bin")] + sorted(glob.glob(os.path.join(local, "*", "bin"))):
        if os.path.isdir(d):
            cands.append((d, "tools/gcc-arm"))
    cands.append((None, "PATH"))
    return cands


def arm_tool(bindir, tool):
    """Full path of arm-none-eabi-<tool> in bindir (None = PATH), or None."""
    return _which_in(ARM_PREFIX + tool, bindir)


def arm_toolchain(explicit=None):
    """(bindir, source) of the first candidate holding arm-none-eabi-as.
    bindir is the resolved directory even for a PATH hit."""
    tried = []
    for bindir, src in arm_toolchain_candidates(explicit):
        p = arm_tool(bindir, "as")
        if p:
            return os.path.dirname(os.path.abspath(p)), src
        tried.append("%s: %s" % (src, bindir or "not on PATH"))
    raise EnvError("arm-none-eabi-as not found (tried %s); unpack the xpack "
                   "arm-none-eabi-gcc zip into tools/gcc-arm/" % "; ".join(tried))


# ---------------------------------------------------------------------------
# CodeWarrior (mwccarm, Windows binaries)
# ---------------------------------------------------------------------------

def mwcc_dir():
    """Root of the CodeWarrior collection: dsi/<version>/ holds the TWL line."""
    return os.path.join(TOOLS, "mwccarm", "mwccarm")


def mwcc_exe(version, tool="mwccarm"):
    """Path of <tool>.exe for one version.  ``version`` is a dsi/ subdirectory
    (``1.1p1``) or a slash-separated tree such as ``2.0/sp2``.  May not exist."""
    base = mwcc_dir()
    dsi = os.path.join(base, "dsi", *version.split("/"))
    cand = os.path.join(dsi, tool + ".exe")
    if os.path.exists(cand) or "/" not in version:
        return cand
    return os.path.join(base, *(version.split("/") + [tool + ".exe"]))


def wine_runner():
    """[] on Windows; [wine64] or [wine] elsewhere.  EnvError if missing."""
    if IS_WINDOWS:
        return []
    for name in ("wine64", "wine"):
        p = shutil.which(name)
        if p:
            return [p]
    raise EnvError("mwccarm.exe is a Windows binary and neither wine64 nor wine "
                   "is on PATH; install wine (Homebrew: brew install --cask "
                   "wine-stable; Debian/Ubuntu: apt install wine)")


def windows_cmd(cmd):
    """Prefix a command whose program is a .exe with the wine runner when not
    on Windows.  Other commands pass through unchanged."""
    cmd = list(cmd)
    if cmd and isinstance(cmd[0], str) and cmd[0].lower().endswith(".exe"):
        return wine_runner() + cmd
    return cmd


def wine_env(env):
    """Quiet wine's diagnostics in a subprocess environment (no-op on Windows)."""
    env.setdefault("WINEDEBUG", "-all")
    env.setdefault("WINEDLLOVERRIDES", "mscoree,mshtml=")
    return env


# ---------------------------------------------------------------------------
# host C toolchain (eidos, the native port)
# ---------------------------------------------------------------------------

_HOST_DIRS = {
    "gcc": ("gcc-host", ("*", "bin")),
    "g++": ("gcc-host", ("*", "bin")),
    "windres": ("gcc-host", ("*", "bin")),
    "cmake": ("cmake", ("*", "bin")),
    "ninja": ("ninja", ()),
}


def host_tool_dirs(name):
    """Bundled directories searched for one host tool, in priority order."""
    sub, pattern = _HOST_DIRS.get(name, ("gcc-host", ("*", "bin")))
    base = os.path.join(TOOLS, sub)
    dirs = [base, os.path.join(base, "bin")]
    if pattern:
        dirs += sorted(glob.glob(os.path.join(base, *pattern)))
    if name == "cmake":   # the macOS .app bundle layout
        dirs += sorted(glob.glob(os.path.join(base, "*", "CMake.app", "Contents", "bin")))
    return [d for d in dirs if os.path.isdir(d)]


def host_tool(name):
    """(path, source) of a host tool, bundled first, then PATH.  None if absent."""
    for d in host_tool_dirs(name):
        p = _which_in(name, d)
        if p:
            return p, "tools/" + os.path.relpath(d, TOOLS).replace(os.sep, "/")
    p = shutil.which(name)
    return (p, "PATH") if p else (None, "missing")


# ---------------------------------------------------------------------------
# scratch space
# ---------------------------------------------------------------------------

def scratch_dir(*sub):
    """ALETHEIA_SCRATCH, else <tempdir>/aletheia, plus optional subdirectories;
    created on demand."""
    base = os.environ.get("ALETHEIA_SCRATCH") or os.path.join(tempfile.gettempdir(), "aletheia")
    d = os.path.join(base, *sub)
    os.makedirs(d, exist_ok=True)
    return d


# ---------------------------------------------------------------------------

def report():
    """Lines describing what this machine resolved to."""
    out = ["platform      %s" % sys.platform,
           "repo root     %s" % ROOT,
           "python        %s (%s)" % (PYTHON, sys.version.split()[0])]
    try:
        bindir, src = arm_toolchain()
        out.append("arm binutils  %s  [%s]" % (bindir, src))
    except EnvError as exc:
        out.append("arm binutils  MISSING: %s" % exc)
    vers = sorted(os.listdir(os.path.join(mwcc_dir(), "dsi"))) if os.path.isdir(os.path.join(mwcc_dir(), "dsi")) else []
    out.append("mwccarm dir   %s  (dsi: %s)" % (mwcc_dir(), " ".join(vers) or "none"))
    try:
        r = wine_runner()
        out.append("mwcc runner   %s" % (r[0] if r else "direct (Windows)"))
    except EnvError as exc:
        out.append("mwcc runner   MISSING: %s" % exc)
    for t in ("gcc", "cmake", "ninja"):
        p, src = host_tool(t)
        out.append("host %-8s %s  [%s]" % (t, p or "-", src))
    out.append("scratch       %s" % scratch_dir())
    return out


if __name__ == "__main__":
    print("\n".join(report()))
