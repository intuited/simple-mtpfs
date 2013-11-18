/* ***** BEGIN LICENSE BLOCK *****
*   Copyright (C) 2012-2013, Peter Hatina <phatina@gmail.com>
*
*   This program is free software; you can redistribute it and/or
*   modify it under the terms of the GNU General Public License as
*   published by the Free Software Foundation; either version 2 of
*   the License, or (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program. If not, see <http://www.gnu.org/licenses/>.
* ***** END LICENSE BLOCK ***** */

#ifndef SMTPFS_TMP_FILES_POOL_H
#define SMTPFS_TMP_FILES_POOL_H

#include <set>
#include <string>
#include <utility>
#include "simple-mtpfs-type-tmp-file.h"

class TmpFilesPool
{
public:
    TmpFilesPool();
    ~TmpFilesPool();

    void setTmpDir(const std::string &path) { m_tmp_path = path; }

    void addFile(const TypeTmpFile &tmp);
    void removeFile(int desc);
    bool empty() const { return m_pool.size(); }
    const TypeTmpFile *getFile(int desc) const;

    std::string makeTmpPath(const std::string &path_device) const;

private:
    std::string m_tmp_path;
    std::set<TypeTmpFile> m_pool;
};

#endif // SMTPFS_TMP_FILES_POOL_H
