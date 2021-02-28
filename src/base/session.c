#include <pwd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

#include "commands/builtins.h"
#include "session.h"

// Setup process for a login shell
void logged_session()
{
    struct passwd* pw;
    uid_t usr;

    usr = geteuid();
    pw = getpwuid(usr);

    homedir = pw->pw_dir;
    gethostname(hostname, sizeof(hostname)); // Repl.it might put this line as a warning

    user = pw->pw_name;

    chdir(homedir);
    getcwd(cwd, sizeof(cwd));

    is_logged = true;
}

// Setup process for a non-login shell
void non_logged_session()
{
    chdir("/");
    getcwd(cwd, sizeof(cwd));

    is_logged = false;
}