{
    "targets": [
        {
            "target_name": "addon",
            "sources": [ "addon.cc" ],
            'includes': [
                '../Electron/vendor/download/libchromiumcontent/filenames.gypi'
            ],
            "include_dirs": [
                "renderer/src",
                "../Electron/atom/",
                "../Electron/vendor/download/libchromiumcontent/src",
                "../Electron/vendor/native_mate/"
                ],
            "link_settings" : {
                "libraries": [
                "-Wl,-rpath,./renderer/generated/cmake/build",
                "-L<!(pwd)/renderer/generated/cmake/build",
                "-lRenderer",
                "-L<(libchromiumcontent_static_libraries_dir)",
                "-lchromiumcontent",
                "-Wl,-rpath,<(libchromiumcontent_shared_libraries_dir)"]
            }
        }
    ]
}
