import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CSVConverter {
    public static void main(String[] args) {
        String inputFilePath = "C:\\Users\\ahmad\\Documents\\Nouveau dossier\\USGS_Final_MagPos_modif.csv";
        String outputFilePath = "C:\\Users\\\\ahmad\\Documents\\Nouveau dossier\\USGS_Final_MagPos_modif_final2.csv";

        // Appel de la méthode pour convertir le fichier CSV
        convertCSV(inputFilePath, outputFilePath);
    }

    private static void convertCSV(String inputFilePath, String outputFilePath) {
        try {
            // Un objet Scanner pour lire le fichier d'entrée
            Scanner scanner = new Scanner(new File(inputFilePath));
            // Un objet PrintWriter pour écrire dans le fichier de sortie
            PrintWriter writer = new PrintWriter(new File(outputFilePath));

            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                // Remplacer le séparateur "|" par ";"
                String newLine = line.replace("|", ";");
                writer.println(newLine);
            }

            scanner.close();
            writer.close();

            System.out.println("Conversion terminée avec succès.");

        } catch (FileNotFoundException e) {
            System.err.println("Erreur : Fichier non trouvé");
            e.printStackTrace();
        }
    }
}
