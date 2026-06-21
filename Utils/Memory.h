//
// Created by alexandr on 27.04.2026.
//

#ifndef LIMEWARE_STANDOFF2_DUMPER_MEMORY_H
#define LIMEWARE_STANDOFF2_DUMPER_MEMORY_H


#include <string>
#include <functional>

class Memory {
public:
    Memory() = default;
    ~Memory() = default;

    struct ModuleInfo {
        ModuleInfo() = default;
        ~ModuleInfo() = default;

        std::string path;
        uintptr_t base = 0;
        uintptr_t end = 0;
        uintptr_t size = 0;

        [[nodiscard]] bool isValid() const { return base && end && end - base > 0 && !path.empty(); }
        [[nodiscard]] std::string getPath() const { return path; }
        [[nodiscard]] uintptr_t getBase() const { return base; }
        [[nodiscard]] uintptr_t getEnd() const { return end; }
        [[nodiscard]] uintptr_t getSize() const { return size; }

        [[nodiscard]] std::vector<uintptr_t> findPattern(const std::string &hex, bool need_first_only = true) const;
    };

    virtual bool initialize();

private:
    ModuleInfo m_libunity = {};
    ModuleInfo getModuleInfo(const char *name, const std::function<void(ModuleInfo)> &callback = {});

    uintptr_t findAssembliesStart(ModuleInfo module);
    uintptr_t findAssembliesEnd(ModuleInfo module);

    uintptr_t findAssemblyOpen(ModuleInfo module);
    uintptr_t findAssemblyName(ModuleInfo module);
    uintptr_t findAssemblyGetImage(ModuleInfo module);

    uintptr_t findImageTypeCount(ModuleInfo module);
    uintptr_t findGetAssemblyTypeHandle(ModuleInfo module);
    uintptr_t findGetTypeFromHandle(ModuleInfo module);
    uintptr_t findImageName(ModuleInfo module);

    uintptr_t findClassGetName(ModuleInfo module);
    uintptr_t findClassNamespace(ModuleInfo module);
    uintptr_t findClassGetParent(ModuleInfo module);
    uintptr_t findClassGetFields(ModuleInfo module);
    uintptr_t findClassGetProperties(ModuleInfo module);
    uintptr_t findClassGetMethods(ModuleInfo module);
    uintptr_t findClassGetType(ModuleInfo module);
    uintptr_t findClassGetEnumBasetype(ModuleInfo module);
    uintptr_t findClassGetFlags(ModuleInfo module);
    uintptr_t findClassGetInterfaces(ModuleInfo module);
    uintptr_t findClassGetDeclaringType(ModuleInfo module);
    uintptr_t findClassGetIsGeneric(ModuleInfo module);

    uintptr_t findFieldGetName(ModuleInfo module);
    uintptr_t findFieldGetOffset(ModuleInfo module);
    uintptr_t findFieldGetType(ModuleInfo module);
    uintptr_t findFieldGetDefaultValue(ModuleInfo module);

    uintptr_t findTypeGetType(ModuleInfo module);
    uintptr_t findTypeAttrs(ModuleInfo module);
    uintptr_t findTypeAttrsShift(ModuleInfo module);
    uintptr_t findTypeGetClassFromType(ModuleInfo module);
    uintptr_t findTypeGetData(ModuleInfo module);
    uintptr_t findTypeGetName(ModuleInfo module);

    uintptr_t findPropertyName(ModuleInfo module);
    uintptr_t findPropertyGetMethod(ModuleInfo module);
    uintptr_t findPropertySetMethod(ModuleInfo module);

    uintptr_t findMethodName(ModuleInfo module);
    uintptr_t findMethodReturnType(ModuleInfo module);
    uintptr_t findMethodGetFlags(ModuleInfo module);
    uintptr_t findMethodParametersCount(ModuleInfo module);
    uintptr_t findMethodGetParameter(ModuleInfo module);
    uintptr_t findMethodPointer(ModuleInfo module);
    uintptr_t findMethodVirtualPointer(ModuleInfo module);
    uintptr_t findMethodSlot(ModuleInfo module);
    uintptr_t findMethodGetIsGeneric(ModuleInfo module);
    uintptr_t findMethodGetParameterName(ModuleInfo module);

public:

    struct {
        uintptr_t assemblies_start = UINTPTR_MAX; // 0xADD7138
        uintptr_t assemblies_end = UINTPTR_MAX; // 0xADD7140

        //assembly
        uintptr_t assembly_open = UINTPTR_MAX; // 0x5B7A554
        uintptr_t assembly_name = UINTPTR_MAX; // 0x18
        uintptr_t assembly_get_image = UINTPTR_MAX; // 0x5B7A54C

        // image
        uintptr_t image_type_count = UINTPTR_MAX; // 0x44
        uintptr_t image_get_assembly_type_handle = UINTPTR_MAX; // 0x9B6C8C4
        uintptr_t handle_get_type_from_handle = UINTPTR_MAX; // 0x9B6CD48
        uintptr_t image_name = UINTPTR_MAX; // 0x30

        // class
        uintptr_t class_get_name = UINTPTR_MAX; // 0x9B3BB74
        uintptr_t class_namespace = UINTPTR_MAX; // 0xF0
        uintptr_t class_get_parent = UINTPTR_MAX; // 0x9B3BC68
        uintptr_t class_get_fields = UINTPTR_MAX; // 0x9B3B728
        uintptr_t class_get_properties = UINTPTR_MAX; // 0x9B3BC70
        uintptr_t class_get_methods = UINTPTR_MAX; // 0x9B3B988
        uintptr_t class_type = UINTPTR_MAX; // 0x20
        uintptr_t class_get_enum_basetype = UINTPTR_MAX; // 0x9B3B644
        uintptr_t class_get_flags = UINTPTR_MAX; // 0x5B76368
        uintptr_t class_get_interfaces = UINTPTR_MAX; // 0x9B3B8C0
        uintptr_t class_get_declaring_type = UINTPTR_MAX; // 0x9B3E44C
        uintptr_t class_get_is_generic = UINTPTR_MAX; // 0x9B3C1FC

        // field
        uintptr_t field_get_name = UINTPTR_MAX; // 0x5B76840
        uintptr_t field_get_offset = UINTPTR_MAX; // 0x4D7D72C
        uintptr_t field_get_type = UINTPTR_MAX; // 0x4D7D730
        uintptr_t field_get_default_value = UINTPTR_MAX; // 0x9B6C290

        // type
        uintptr_t type_get_type = UINTPTR_MAX; // 0x4D7D744
        uintptr_t type_attrs = UINTPTR_MAX; // 0x10
        uintptr_t type_attrs_shift = UINTPTR_MAX; // 0x2
        uintptr_t type_get_class_from_type = UINTPTR_MAX; // 0x9B3B06C
        uintptr_t type_get_data = UINTPTR_MAX; // 0x9B7C880
        uintptr_t type_get_name = UINTPTR_MAX; // 0x9B7C884

        // property
        uintptr_t property_name = UINTPTR_MAX; // 0x10
        uintptr_t property_get_method = UINTPTR_MAX; // 0x0
        uintptr_t property_set_method = UINTPTR_MAX; // 0x20

        // method
        uintptr_t method_name = UINTPTR_MAX; // 0x18
        uintptr_t method_return_type = UINTPTR_MAX; // 0x28
        uintptr_t method_get_flags = UINTPTR_MAX; // 0x60822E4
        uintptr_t method_parameters_count = UINTPTR_MAX; // 0x0
        uintptr_t method_get_parameter = UINTPTR_MAX; // 0x9B6E678
        uintptr_t method_pointer = UINTPTR_MAX; // 0x48
        uintptr_t method_virtual_pointer = UINTPTR_MAX; // 0x30
        uintptr_t method_slot = UINTPTR_MAX; // 0x52
        uintptr_t method_get_is_generic = UINTPTR_MAX; // 0x5B76558
        uintptr_t method_get_parameter_name = UINTPTR_MAX; // 0x9B6E698
    } offsets;

    [[nodiscard]] uintptr_t getUnityBase() const { return m_libunity.getBase(); }
    [[nodiscard]] uintptr_t getUnityEnd() const { return m_libunity.getEnd(); }
    [[nodiscard]] uintptr_t getUnitySize() const { return m_libunity.getSize(); }

    [[nodiscard]] std::string dumpHex(uintptr_t address, size_t size);
    void dumpHexToFile(uintptr_t address, size_t size, const std::string& filePath);
    [[nodiscard]] bool isPtrValid(uintptr_t address) const;
};



#endif //LIMEWARE_STANDOFF2_DUMPER_MEMORY_H