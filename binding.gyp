{
    "targets": [
        {
            "target_name": "addon",
            "sources": [ "addon.cc" ],
            "include_dirs": [ "renderer/src" ],
            "link_settings" : {
                "libraries": [
                "-Wl,-rpath,./renderer/generated/cmake/build",
                "-L<!(pwd)/renderer/generated/cmake/build",
                "-lRenderer" ]
            }
        }
    ]
}
