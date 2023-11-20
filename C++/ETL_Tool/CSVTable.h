#pragma once
#include <filesystem>
#include <functional>

class CSVRow;
class CSVHeader;

class CSVTable
{
public:
	CSVTable() = default;

	CSVTable(std::filesystem::path const& filePath, std::string const& delimiter = ",");

	void AddRow(std::shared_ptr<CSVRow> const& row);

	void DeleteColumns(std::vector<std::string> const& columnNames) const;

	void DeleteColumns(std::vector<size_t> columnIndices) const;

	std::unique_ptr<CSVTable> ExtractColumns(std::vector<std::string> const& columnNames) const;

	void RunTransformation(std::vector<std::string> const& columnInputNames,
	                       std::vector<std::string> const& columnOutputNames,
	                       std::function<std::vector<std::string>(std::vector<std::string> const&)> const& transformation,
	                       std::vector<std::string> const& newColumnNames = {}) const;

	void RunTransformation(std::vector<size_t> const& columnInputIndices,
	                       std::vector<size_t> const& columnOutputIndices,
	                       std::function<std::vector<std::string>(std::vector<std::string> const&)> const& transformation) const;

	void ReorganizeColumns(std::vector<std::string> const& newColumnOrder) const;

	void ReorganizeColumns(std::vector<size_t> const& newColumnOrder) const;

	void RenameColumn(size_t columnIndex, std::string const& newColumnName) const;

	void FilterRows(size_t columnIndex, std::string const& filterValue, std::function<bool(std::string const&, std::string const&)> const& predicate);

	void PrintFirstRow() const;

	void Serialize(std::string const& outputPath, std::string const& delimiter = ",") const;

	std::vector<std::string> GetColumnNames() const;

protected:
	static void DeserializeRow(std::shared_ptr<CSVRow> const& row, std::string const& line, std::string const& delimiter = ",", std::shared_ptr<CSVHeader> const& header = nullptr);

private:
	std::vector<std::shared_ptr<CSVRow>> rows;
};
