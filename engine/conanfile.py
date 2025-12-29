from conan import ConanFile

class EngineConan(ConanFile):
    name = "engine"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    requires = "raylib/5.5", "nlohmann_json/3.11.2", "spdlog/1.14.1", "assimp/5.4.3"
    generators = "CMakeDeps", "CMakeToolchain"