from conan import ConanFile

class EngineConan(ConanFile):
    name = "engine"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    requires = "raylib/5.5"
    generators = "CMakeDeps", "CMakeToolchain" 