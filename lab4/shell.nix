let
  pkgs = import (fetchTarball "https://github.com/NixOS/nixpkgs/archive/nixos-23.11.tar.gz") {};
in
pkgs.mkShell {
  packages = [ pkgs.verilator ];
}

