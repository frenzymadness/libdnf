#ifndef SACK_H
#define SACK_H

// libsolv
#include "solv/pool.h"

// hawkey
#include "repo.h"
#include "package.h"
#include "types.h"

#define SYSTEM_REPO_NAME "@System"
#define SYSTEM_RPMDB "/var/lib/rpm/Packages"
#define CMDLINE_REPO_NAME "@commandline"
#define HY_EXT_FILENAMES "-filenames"

HySack hy_sack_create(void);
void hy_sack_free(HySack sack);
char *hy_sack_solv_path(HySack sack, const char *reponame, const char *ext);
void hy_sack_set_cache_path(HySack sack, const char *path);
void hy_sack_create_cmdline_repo(HySack sack);
HyPackage hy_sack_add_cmdline_rpm(HySack sack, const char *fn);
void hy_sack_load_rpm_repo(HySack sack);
void hy_sack_load_yum_repo(HySack sack, HyRepo repo);
void hy_sack_solve(HySack sack, Queue *job, Map *res_map, int mode);
int hy_sack_load_filelists(HySack sack);
int hy_sack_write_all_repos(HySack sack);
int hy_sack_write_filelists(HySack sack);

#endif // SACK_H
