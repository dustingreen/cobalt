// Copyright 2017 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#if SB_API_VERSION < 17
#include "starboard/directory.h"

#include <android/asset_manager.h>

#include "starboard/android/shared/file_internal.h"

#include "starboard/android/shared/directory_internal.h"
#include "starboard/shared/iso/impl/directory_close.h"

bool SbDirectoryClose(SbDirectory directory) {
  if (directory && directory->asset_dir) {
    AAssetDir_close(directory->asset_dir);
    delete directory;
    return true;
  }

  return ::starboard::shared::iso::impl::SbDirectoryClose(directory);
}
#endif  // SB_API_VERSION < 17
